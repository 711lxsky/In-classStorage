package OMWork7;

import javax.swing.*;

public class InteractiveGUIProgram {
    public static void main(String[] args) {
        // 创建窗口
        JFrame frame = new JFrame("交互式GUI程序");

        // 设置窗口关闭操作
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        // 创建按钮
        JButton button = new JButton("点击我");
        button.addActionListener(e -> {
            // 在按钮点击事件中进行交互
            String name = JOptionPane.showInputDialog(frame, "请输入您的名字：");
            JOptionPane.showMessageDialog(frame, "你好，" + name + "！");
        });

        // 创建面板
        JPanel panel = new JPanel();
        panel.add(button);

        // 将面板添加到窗口中
        frame.getContentPane().add(panel);

        // 设置窗口大小并显示
        frame.setSize(300, 250);
        frame.setVisible(true);
    }
}
