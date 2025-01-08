package main

import (
	"fmt"
	"net"
	"net/http"
	"strings"

	"github.com/gin-gonic/gin"
)

func getLocalWLANIP() string {
	interfaces, err := net.Interfaces()
	if err != nil {
		fmt.Println("Error getting network interfaces:", err)
		return "localhost"
	}

	for _, iface := range interfaces {
		if strings.Contains(strings.ToLower(iface.Name), "wlan") || strings.Contains(strings.ToLower(iface.Name), "wifi") {
			addrs, err := iface.Addrs()
			if err != nil {
				continue
			}
			for _, addr := range addrs {
				ipNet, ok := addr.(*net.IPNet)
				if ok && !ipNet.IP.IsLoopback() && ipNet.IP.To4() != nil {
					return ipNet.IP.String()
				}
			}
		}
	}

	return "localhost"
}

func main() {
	r := gin.Default()

	// 静态文件服务（用于加载 CSS、JS 等）
	r.Static("/static", "./main/static")

	// 设置HTML模板路径
	r.LoadHTMLGlob("templates/*")

	// 添加自定义中间件，用于打印请求的URL
	r.Use(func(c *gin.Context) {
		fmt.Println("Request URL:", c.Request.URL)
		c.Next()
	})

	r.GET("/", func(c *gin.Context) {
		c.HTML(http.StatusOK, "login.html", nil)
	})

	// 处理登录请求
	r.POST("/login", func(c *gin.Context) {
		username := c.PostForm("username")
		password := c.PostForm("password")
		c.JSON(http.StatusOK, gin.H{
			"message":  "Login successful",
			"username": username,
			"password": password,
		})
	})

	port := ":8080" // 使用端口 8080
	localIP := getLocalWLANIP()
	fmt.Printf("Server is running at http://%s%s\n", localIP, port)

	// 启动服务器
	r.Run(port)
}
