import javax.swing.*;
import javax.swing.table.DefaultTableModel;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;

public class MainFrame extends JFrame {

    private JTextField textField;
    private JTable table;
    private DefaultTableModel tableModel;
    private DatabaseHelper dbHelper;

    public MainFrame() {
        dbHelper = new DatabaseHelper();

        // Frame settings
        setTitle("数据库操作");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setBounds(100, 100, 800, 600);

        // Main content pane
        JPanel contentPane = new JPanel(new BorderLayout());
        setContentPane(contentPane);

        // North panel
        JPanel northPanel = new JPanel();
        contentPane.add(northPanel, BorderLayout.NORTH);
        northPanel.setLayout(new FlowLayout());

        JLabel lblNewLabel = new JLabel("班级/学号/姓名/性别/年龄：");
        northPanel.add(lblNewLabel);

        textField = new JTextField();
        northPanel.add(textField);
        textField.setColumns(20);

        JButton btnQuery = new JButton("查询");
        northPanel.add(btnQuery);
        btnQuery.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                // 查询按钮事件
                queryAction();
            }
        });

        JButton btnUpdate = new JButton("修改");
        northPanel.add(btnUpdate);
        btnUpdate.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                // 修改按钮事件
                updateAction();
            }
        });

        JButton btnDelete = new JButton("删除");
        northPanel.add(btnDelete);
        btnDelete.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                // 删除按钮事件
                deleteAction();
            }
        });

        JButton btnAdd = new JButton("新增");
        northPanel.add(btnAdd);
        btnAdd.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                // 新增按钮事件
                addAction();
            }
        });

        JButton btnSave = new JButton("保存");
        northPanel.add(btnSave);
        btnSave.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                // 保存按钮事件
                saveAction();
            }
        });

        // Center panel with scroll pane and table
        JScrollPane scrollPane = new JScrollPane();
        contentPane.add(scrollPane, BorderLayout.CENTER);

        tableModel = new DefaultTableModel(
                new Object[][]{},
                new String[]{"班级", "学号", "姓名", "性别", "年龄"}
        );
        table = new JTable(tableModel);
        scrollPane.setViewportView(table);

        // South panel for pagination
        JPanel southPanel = new JPanel();
        contentPane.add(southPanel, BorderLayout.SOUTH);

        JButton btnFirst = new JButton("第一页");
        southPanel.add(btnFirst);

        JButton btnPrevious = new JButton("上一页");
        southPanel.add(btnPrevious);

        JButton btnNext = new JButton("下一页");
        southPanel.add(btnNext);

        JButton btnLast = new JButton("最后页");
        southPanel.add(btnLast);
    }

    private void queryAction() {
        // 实现查询功能
        String queryText = textField.getText();
        String sql = "SELECT * FROM students WHERE CONCAT(id, className, stuNo, stuName, sex, sage) LIKE '%" + queryText + "%'";
        try {
            ResultSet rs = dbHelper.query(sql);
            tableModel.setRowCount(0); // 清空表格
            while (rs.next()) {

                String className = rs.getString("className");
                String studentNo = rs.getString("stuNo");
                String name = rs.getString("stuName");
                String gender = rs.getString("sex");
                int age = rs.getInt("sage");
                tableModel.addRow(new Object[]{className, studentNo, name, gender, age});
            }
            dbHelper.close(null, null, rs);
        } catch (SQLException e) {
            e.printStackTrace();
        }
    }

    private void updateAction() {
        // 实现修改功能
        int selectedRow = table.getSelectedRow();
        if (selectedRow != -1) {
            String className = (String) tableModel.getValueAt(selectedRow, 0);
            String studentNo = (String) tableModel.getValueAt(selectedRow, 1);
            String name = (String) tableModel.getValueAt(selectedRow, 2);
            String gender = (String) tableModel.getValueAt(selectedRow, 3);
            int age = (int) tableModel.getValueAt(selectedRow, 4);

            // 假设只修改姓名
            String newName = JOptionPane.showInputDialog("请输入新的姓名：", name);
            if (newName != null && !newName.trim().isEmpty()) {
                String sql = "UPDATE students SET stuName = ? WHERE className = ? AND stuNo = ?";
                try {
                    Connection conn = dbHelper.connect();
                    PreparedStatement stmt = conn.prepareStatement(sql);
                    stmt.setString(1, newName);
                    stmt.setString(2, className);
                    stmt.setString(3, studentNo);
                    stmt.executeUpdate();
                    dbHelper.close(conn, stmt, null);
                    tableModel.setValueAt(newName, selectedRow, 2);
                } catch (SQLException e) {
                    e.printStackTrace();
                }
            }
        }
    }

    private void deleteAction() {
        // 实现删除功能
        int selectedRow = table.getSelectedRow();
        if (selectedRow != -1) {
            String className = (String) tableModel.getValueAt(selectedRow, 0);
            String studentNo = (String) tableModel.getValueAt(selectedRow, 1);

            String sql = "DELETE FROM students WHERE className = ? AND stuNo = ?";
            try {
                Connection conn = dbHelper.connect();
                PreparedStatement stmt = conn.prepareStatement(sql);
                stmt.setString(1, className);
                stmt.setString(2, studentNo);
                stmt.executeUpdate();
                dbHelper.close(conn, stmt, null);
                tableModel.removeRow(selectedRow);
            } catch (SQLException e) {
                e.printStackTrace();
            }
        }
    }

    private void addAction() {
        // 实现新增功能
        String className = JOptionPane.showInputDialog("请输入班级：");
        String studentNo = JOptionPane.showInputDialog("请输入学号：");
        String name = JOptionPane.showInputDialog("请输入姓名：");
        String gender = JOptionPane.showInputDialog("请输入性别：");
        String ageStr = JOptionPane.showInputDialog("请输入年龄：");

        if (className != null && studentNo != null && name != null && gender != null && ageStr != null) {
            int age = Integer.parseInt(ageStr);
            String sql = "INSERT INTO students (className, stuNo, stuName, sex, sage) VALUES (?, ?, ?, ?, ?)";
            try {
                Connection conn = dbHelper.connect();
                PreparedStatement stmt = conn.prepareStatement(sql);
                stmt.setString(1, className);
                stmt.setString(2, studentNo);
                stmt.setString(3, name);
                stmt.setString(4, gender);
                stmt.setInt(5, age);
                stmt.executeUpdate();
                dbHelper.close(conn, stmt, null);
                tableModel.addRow(new Object[]{className, studentNo, name, gender, age});
            } catch (SQLException e) {
                e.printStackTrace();
            }
        }
    }

    private void saveAction() {
        // 实现保存功能
        JOptionPane.showMessageDialog(this, "保存成功！");
    }

}
