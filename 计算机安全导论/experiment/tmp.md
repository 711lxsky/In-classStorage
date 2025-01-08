```Go
package main

import (
	"encoding/binary" // 编码
	"fmt"             // 流处理、打印信息
)

const (
	// SHA-1初始哈希值
	h0 = 0x67452301
	h1 = 0xEFCDAB89
	h2 = 0x98BADCFE
	h3 = 0x10325476
	h4 = 0xC3D2E1F0

	// SHA-1常量
	k1 = 0x5A827999
	k2 = 0x6ED9EBA1
	k3 = 0x8F1BBCDC
	k4 = 0xCA62C1D6
)

// 左旋转操作
func leftRotate(value uint32, shift uint) uint32 {
	return (value << shift) | (value >> (32 - shift))
}

// 消息预处理
func preprocess(message []byte) []byte {
	// 计算消息的长度（以位为单位）
	ml := uint64(len(message) * 8)

	// 填充消息，使长度为512位的倍数
	message = append(message, 0x80) // 添加一个1位
	for len(message)%64 != 56 {
		message = append(message, 0x00) // 填充0直到满足条件
	}

	// 添加消息的长度（64位）
	mlBytes := make([]byte, 8)
	binary.BigEndian.PutUint64(mlBytes, ml)
	message = append(message, mlBytes...)

	return message
}

// 处理消息块
func processBlock(block []byte, h []uint32) {
	// 将块分成16个32位的字
	var w [80]uint32
	for i := 0; i < 16; i++ {
		w[i] = binary.BigEndian.Uint32(block[i*4 : (i+1)*4])
	}

	// 扩展到80个字
	for i := 16; i < 80; i++ {
		w[i] = leftRotate(w[i-3]^w[i-8]^w[i-14]^w[i-16], 1)
	}

	a, b, c, d, e := h[0], h[1], h[2], h[3], h[4]

	// 主循环
	for i := 0; i < 80; i++ {
		var f, k uint32
		if i < 20 {
			f = (b & c) | ((^b) & d)
			k = k1
		} else if i < 40 {
			f = b ^ c ^ d
			k = k2
		} else if i < 60 {
			f = (b & c) | (b & d) | (c & d)
			k = k3
		} else {
			f = b ^ c ^ d
			k = k4
		}

		// 计算中间结果
		temp := leftRotate(a, 5) + f + e + k + w[i]
		e = d
		d = c
		c = leftRotate(b, 30)
		b = a
		a = temp

		// 输出每一轮的中间结果
		fmt.Printf("Round %d: A=%x B=%x C=%x D=%x E=%x\n", i, a, b, c, d, e)
	}

	// 更新哈希值
	h[0] += a
	h[1] += b
	h[2] += c
	h[3] += d
	h[4] += e
}

// SHA-1算法主函数
func sha1(message []byte) [20]byte {
	// 初始化哈希值
	h := [5]uint32{h0, h1, h2, h3, h4}

	// 预处理消息
	message = preprocess(message)

	// 处理每一个512位的块
	for i := 0; i < len(message); i += 64 {
		block := message[i : i+64]
		processBlock(block, h[:])
	}

	// 将哈希值转换为字节数组
	var hash [20]byte
	for i := 0; i < 5; i++ {
		binary.BigEndian.PutUint32(hash[i*4:(i+1)*4], h[i])
	}

	return hash
}

func main() {
	fmt.Printf("========= 这里是计算机安全导论实验1--SHA1算法实现测试 =========\n")
	fmt.Print("输入测试字符串：")
	var input string
	_, err := fmt.Scanln(&input)
	if err != nil {
		fmt.Printf("输入错误: %v\n", err)
		return
	}
	fmt.Print("请输入测试次数（默认3次）：")
	count := 3
	_, err = fmt.Scanf("%d", &count)
	if err != nil {
		fmt.Printf("使用默认值")
	}
	fmt.Printf("输入的字符串为： %s,  测试次数： %d \n", input, count)
	fmt.Println("========== 输入完成，开始计算SHA-1哈希值 ==========")
	sha1Res := make([][20]byte, count)
	for i := 1; i <= count; i++ {
		fmt.Printf("\n######### 第%d次测试 ########\n", i)
		message := []byte(input)
		hash := sha1(message)
		fmt.Printf("---------- SHA-1计算结果: %x\n", hash)
		sha1Res[i-1] = hash
	}
	fmt.Printf("\n各次加密结果：\n")
	for i, hash := range sha1Res {
		fmt.Printf("第%d次 ：%x\n", i+1, hash)
	}
	fmt.Println("\n========== 测试结束 ==========")
}

```