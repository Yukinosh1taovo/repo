package com.itheima.ui;

import javax.swing.*;

public class LoginJFrame extends JFrame {

    public LoginJFrame(){

        setSize(488,430);
        // 设置界面置顶
        setAlwaysOnTop(true);
        // 设置界面居中
        setLocationRelativeTo(null);
        // 设置默认关闭操作
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        setVisible(true);
    }
}
