package com.zx;

import javax.swing.*;

public class JFrameTest {
    public static void main(String[] args) {

        JFrame jf = new JFrame("数据库");
        jf.setVisible(true);

        jf.setLocation(300,150);
        jf.setSize(800, 600);
        // jf.setBounds(300,150,1280,720);

        jf.setDefaultCloseOperation(WindowConstants.EXIT_ON_CLOSE);

    }
}
