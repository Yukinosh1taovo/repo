package com.itheima.ui;

import javax.swing.*;

public class GameJFrame extends JFrame {

    public GameJFrame(){

        // 初始化界面
        initJFrame();

        // 初始化菜单
        initJMenuBar();

        // 初始化图片
        initImage();


        // 展示界面 写在最后
        setVisible(true);
    }





    private void initJFrame() {
        // 设置界面宽高
        setSize(603,680);
        // 设置界面标题
        setTitle("拼图单机版 v1.0");
        // 设置界面置顶
        setAlwaysOnTop(true);
        // 设置界面居中
        setLocationRelativeTo(null);
        // 设置默认关闭操作
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        // 取消默认布局
        setLayout(null);
    }

    private void initJMenuBar() {
        // 初始化菜单
        JMenuBar jMenuBar = new JMenuBar();

        // 创建菜单选项
        JMenu functionJmenu = new JMenu("功能");
        JMenu aboutJmenu = new JMenu("关于我们");

        // 创建菜单选项条目
        JMenuItem replayItem = new JMenuItem("重新游戏");
        JMenuItem reLoginItem = new JMenuItem("重新登录");
        JMenuItem closeItem = new JMenuItem("关闭游戏");

        JMenuItem accountItem = new JMenuItem("公众号");

        // 将条目添加到菜单选项中
        functionJmenu.add(replayItem);
        functionJmenu.add(reLoginItem);
        functionJmenu.add(closeItem);

        aboutJmenu.add(accountItem);

        jMenuBar.add(functionJmenu);
        jMenuBar.add(aboutJmenu);

        setJMenuBar(jMenuBar);
    }

    private void initImage() {
        int num = 1;
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                // 创建一个JLabel对象(管理容器)
                JLabel jLabel = new JLabel(new ImageIcon("C:\\Files\\repo\\idea\\basic-code\\puzzlegame\\image\\animal\\animal3\\"+ num +".jpg"));
                // 指定图片位置
                jLabel.setBounds(105 * j,105 * i,105,105);
                // 把管理容器添加到界面中
                this.getContentPane().add(jLabel);
                num++;

            }

        }


       
        
        
        

    }


}


