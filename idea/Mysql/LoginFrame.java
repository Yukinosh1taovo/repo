import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;

public class LoginFrame extends JFrame {

    private JTextField textField;
    private JPasswordField passwordField;
    private JButton btnLogin, btnCancel;

    public LoginFrame() {
        setTitle("登录");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setBounds(100, 100, 450, 300);
        JPanel contentPane = new JPanel();
        contentPane.setBorder(BorderFactory.createEmptyBorder(5, 5, 5, 5));
        setContentPane(contentPane);
        contentPane.setLayout(null);

        JLabel lblUsername = new JLabel("用户名：");
        lblUsername.setBounds(100, 50, 80, 25);
        contentPane.add(lblUsername);

        textField = new JTextField();
        textField.setBounds(180, 50, 165, 25);
        contentPane.add(textField);
        textField.setColumns(10);

        JLabel lblPassword = new JLabel("密 码：");
        lblPassword.setBounds(100, 100, 80, 25);
        contentPane.add(lblPassword);

        passwordField = new JPasswordField();
        passwordField.setBounds(180, 100, 165, 25);
        contentPane.add(passwordField);

        btnLogin = new JButton("登录");
        btnLogin.setBounds(100, 150, 80, 25);
        contentPane.add(btnLogin);

        btnCancel = new JButton("取消");
        btnCancel.setBounds(265, 150, 80, 25);
        contentPane.add(btnCancel);

        btnLogin.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                String username = textField.getText();
                String password = new String(passwordField.getPassword());
                if (authenticate(username, password)) {
                    JOptionPane.showMessageDialog(null, "登录成功！");
                    dispose();
                    MainFrame dbFrame = new MainFrame();
                    dbFrame.setVisible(true);
                } else {
                    JOptionPane.showMessageDialog(null, "用户名或密码错误！", "登录失败", JOptionPane.ERROR_MESSAGE);
                }
            }
        });

        btnCancel.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                System.exit(0);
            }
        });
    }

    private boolean authenticate(String username, String password) {
        DatabaseHelper dbHelper = new DatabaseHelper();
        Connection conn = null;
        PreparedStatement stmt = null;
        ResultSet rs = null;
        try {
            conn = dbHelper.connect();
            String sql = "SELECT * FROM users WHERE userName = ? AND password = ?";
            stmt = conn.prepareStatement(sql);
            stmt.setString(1, username);
            stmt.setString(2, password);
            rs = stmt.executeQuery();
            return rs.next();
        } catch (SQLException e) {
            e.printStackTrace();
            return false;
        } finally {
            dbHelper.close(conn, stmt, rs);
        }
    }

    public static void main(String[] args) {
        EventQueue.invokeLater(new Runnable() {
            public void run() {
                try {
                    LoginFrame frame = new LoginFrame();
                    frame.setVisible(true);
                } catch (Exception e) {
                    e.printStackTrace();
                }
            }
        });
    }

}
