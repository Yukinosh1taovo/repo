package com.itheima.test;

import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.Random;

public class MyJFrame2 extends JFrame implements ActionListener {

    JButton jbt1 = new JButton("按钮1");
    JButton jbt2 = new JButton("按钮2");

    public MyJFrame2(){
        this.setSize(603,680);
        this.setTitle("测试窗口2");
        this.setAlwaysOnTop(true);
        this.setLocationRelativeTo(null);
        this.setDefaultCloseOperation(EXIT_ON_CLOSE);
        this.setLayout(null);

        jbt1.setBounds(0,0,100,50);
        jbt1.addActionListener(this);

        jbt2.setBounds(100,0,100,50);
        jbt2.addActionListener(this);

        this.getContentPane().add(jbt1);
        this.getContentPane().add(jbt2);

        this.setVisible(true);
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        // 对当前的按钮进行判断

        Object source = e.getSource();

        if (source == jbt1){
            jbt1.setSize(200,200);
        }
        else{
            Random r = new Random();
            jbt2.setLocation(r.nextInt(500),r.nextInt(500));
        }

    }
} 
