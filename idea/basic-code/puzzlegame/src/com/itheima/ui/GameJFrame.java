package com.itheima.ui;

import javax.swing.*;
import javax.swing.border.BevelBorder;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;
import java.util.Random;

public class GameJFrame extends JFrame implements KeyListener, ActionListener {

    public static final int KEY_LEFT = 37;
    public static final int KEY_UP = 38;
    public static final int KEY_RIGHT = 39;
    public static final int KEY_DOWN = 40;
    public static final int KEY_A = 65;
    public static final int KEY_W = 87;

    // 创建一个二维数组
    int[][] data = new int[4][4];
    int empty_x = 0;
    int empty_y = 0;
    String path = "..\\puzzlegame\\image\\girl\\girl1\\";
    int[][] win = {
        {1,2,3,4},
        {5,6,7,8},
        {9,10,11,12},
        {13,14,15,0}
    };
    int step = 0;

    // 创建菜单选项条目
    JMenuItem replayItem = new JMenuItem("重新游戏");
    JMenuItem closeItem = new JMenuItem("关闭游戏");
    JMenuItem accountItem = new JMenuItem("公众号");
    JMenuItem animalItem = new JMenuItem("动物");
    JMenuItem girlItem = new JMenuItem("妹妹");
    JMenuItem sportItem = new JMenuItem("运动");



    public GameJFrame() {


        // 初始化界面
        initJFrame();

        // 初始化菜单
        initJMenuBar();

        // 初始化数据
        initData();

        // 初始化图片
        initImage();


        // 展示界面 写在最后
        setVisible(true);
    }

    private void initJFrame() {
        // 设置界面宽高
        setSize(603, 680);
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

        addKeyListener(this);
    }

    private void initJMenuBar() {
        // 初始化菜单
        JMenuBar jMenuBar = new JMenuBar();

        // 创建菜单选项
        JMenu functionJmenu = new JMenu("功能");
        JMenu changePicMenu = new JMenu("更换图片");
        JMenu aboutJmenu = new JMenu("关于我们");



        replayItem.addActionListener(this);
        closeItem.addActionListener(this);
        accountItem.addActionListener(this);
        girlItem.addActionListener(this);
        animalItem.addActionListener(this);
        sportItem.addActionListener(this);

        // 将条目添加到菜单选项中
        changePicMenu.add(girlItem);
        changePicMenu.add(animalItem);
        changePicMenu.add(sportItem);

        functionJmenu.add(changePicMenu);
        functionJmenu.add(replayItem);
        functionJmenu.add(closeItem);
        aboutJmenu.add(accountItem);

        jMenuBar.add(functionJmenu);
        jMenuBar.add(aboutJmenu);

        setJMenuBar(jMenuBar);
    }

    private void initData() {

        // 1. 创建一维数组
        int[] tempArr = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};

        // 2. 打乱一位数组顺序
        Random r = new Random();
        for (int i = 0; i < tempArr.length; i++) {
            int index = r.nextInt(tempArr.length);
            int temp = tempArr[i];
            tempArr[i] = tempArr[index];
            tempArr[index] = temp;
        }

        for (int i = 0; i < tempArr.length; i++) {
            if(tempArr[i] == 0){
                empty_x = i / 4;
                empty_y = i % 4;
            }
            data[i / 4][i % 4] = tempArr[i];
        }

    }

    private void initImage() {
        // 路径分为 绝对路径和相对路径
        // 先加载的图片在上方， 后加载的图片在下面

        this.getContentPane().removeAll();

        if(victory()){
            JLabel winJLabel = new JLabel(new ImageIcon("C:\\Files\\repo\\idea\\basic-code\\puzzlegame\\image\\win.png"));
            winJLabel.setBounds(203,283,197,73);
            this.getContentPane().add(winJLabel);
        }

        JLabel stepCount = new JLabel("步数：" + step);
        stepCount.setBounds(50,30,100,20);
        this.getContentPane().add(stepCount);


        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                // 创建一个JLabel对象(管理容器)
                JLabel jLabel = new JLabel(new ImageIcon( path + data[i][j] + ".jpg"));
                // 指定图片位置
                jLabel.setBounds(105 * j + 83, 105 * i + 134, 105, 105);
                jLabel.setBorder(new BevelBorder(BevelBorder.LOWERED));
                // 把管理容器添加到界面中
                this.getContentPane().add(jLabel);

            }
        }

        // 加载背景图片
        JLabel background = new JLabel(new ImageIcon("..\\puzzlegame\\image\\background.png"));
        background.setBounds(40,40,508,560);

        this.getContentPane().add(background);
        this.getContentPane().repaint();// 刷新

    }

    public boolean victory(){
        for (int i = 0; i < data.length; i++) {
            for (int j = 0; j < data[i].length; j++) {
                if (data[i][j] != win[i][j]){
                    // 只要有一个数据不一样就返回false
                    return false;
                }
            }
        }
        return true;
    }


    @Override
    public void keyTyped(KeyEvent e) {

    }

    @Override
    public void keyPressed(KeyEvent e) {

        if (victory()) return ;

        int keyCode = e.getKeyCode();
        // 长按A加载目标图片
        if (keyCode == KEY_A){
            this.getContentPane().removeAll();

            JLabel stepCount = new JLabel("步数：" + step);
            stepCount.setBounds(50,30,100,20);
            this.getContentPane().add(stepCount);

            JLabel all = new JLabel(new ImageIcon(path + "all.jpg"));
            all.setBounds(83,134,420,420);
            this.getContentPane().add(all);

            // 加载背景图片
            JLabel background = new JLabel(new ImageIcon("..\\puzzlegame\\image\\background.png"));
            background.setBounds(40,40,508,560);

            this.getContentPane().add(background);
            this.getContentPane().repaint();
        }
    }

    @Override
    public void keyReleased(KeyEvent e) {
        // 如果游戏胜利 直接结束 不执行下面的移动代码’
        if(victory()) return ;

        int code = e.getKeyCode(); // 获取按键代码

        // 向左移动
        if(code == KEY_LEFT) {
            if(empty_y == 3) return ;

            System.out.println("向左移动");
            data[empty_x][empty_y] = data[empty_x][empty_y + 1];
            data[empty_x][empty_y + 1] = 0;
            empty_y++;
            step++;
            initImage();
        }
        // 向右移动
        else if (code == KEY_RIGHT) {
            if (empty_y == 0) return ;

            System.out.println("向右移动");
            data[empty_x][empty_y] = data[empty_x][empty_y - 1];
            data[empty_x][empty_y - 1] = 0;
            empty_y--;
            step++;
            initImage();
        }
        // 向上移动
        else if(code == KEY_UP) {
            if (empty_x == 3) return ;

            System.out.println("向上移动");
            data[empty_x][empty_y] = data[empty_x + 1][empty_y];
            data[empty_x + 1][empty_y] = 0;
            empty_x++;
            step++;
            initImage();
        }
        // 向下移动
        else if (code == KEY_DOWN) {
            if (empty_x == 0) return ;

            System.out.println("向下移动");
            data[empty_x][empty_y] = data[empty_x - 1][empty_y];
            data[empty_x - 1][empty_y] = 0;
            empty_x--;
            step++;
            initImage();
        }
        // 松开A恢复图片
        else if (code == KEY_A) {
            initImage();
        }
        // 按W一键通关
        else if (code == KEY_W) {
            data = new int[][]{
                    {1,2,3,4},
                    {5,6,7,8},
                    {9,10,11,12},
                    {13,14,15,0}};

            initImage();
            empty_x = 3;
            empty_y = 3;
        }

        }

    @Override
    public void actionPerformed(ActionEvent e) {
        Object obj = e.getSource();

        // 重新游戏
        if (obj == replayItem){
            initData();
            step = 0;
            initImage();
        }
        else if (obj == closeItem){
            System.exit(0);
        }
        else if (obj == accountItem){
        JDialog jDialog = new JDialog();
        JLabel jLabel = new JLabel(new ImageIcon("..\\puzzlegame\\image\\about.jpg"));
        jLabel.setBounds(0,0,258,258);
        jDialog.getContentPane().add(jLabel);
        jDialog.setSize(340,340);
        jDialog.setAlwaysOnTop(true);
        jDialog.setLocationRelativeTo(null);
        // 弹窗不关闭则无法操作下方界面
        jDialog.setModal(true);
        jDialog.setVisible(true);
        }
        else if (obj == girlItem){
            step = 0;
            Random r = new Random();
            path = "..\\puzzlegame\\image\\girl\\girl" + (r.nextInt(11) + 1) + "\\";
            System.out.println(path);
            initData();
            initImage();
        }
        else if (obj == animalItem){
            step = 0;
            Random r = new Random();
            path = "..\\puzzlegame\\image\\animal\\animal" + (r.nextInt(8) + 1) + "\\";
            System.out.println(path);
            initData();
            initImage();
        }
        else if (obj == sportItem){
            step = 0;
            Random r = new Random();
            path = "..\\puzzlegame\\image\\sport\\sport" + (r.nextInt(10) + 1) + "\\";
            System.out.println(path);
            initData();
            initImage();
        }

    }
}


