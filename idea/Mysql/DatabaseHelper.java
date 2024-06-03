import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;

public class DatabaseHelper {

    private static final String URL = "jdbc:mysql://localhost:3306/db_student?useSSL=false&serverTimezone=UTC";
    private static final String USER = "root";  // 修改为你的数据库用户名
    private static final String PASSWORD = "123456";  // 修改为你的数据库密码

    public Connection connect() throws SQLException {
        return DriverManager.getConnection(URL, USER, PASSWORD);
    }

    public ResultSet query(String sql) throws SQLException {
        Connection conn = connect();
        PreparedStatement stmt = conn.prepareStatement(sql);
        return stmt.executeQuery();
    }

    public int update(String sql) throws SQLException {
        Connection conn = connect();
        PreparedStatement stmt = conn.prepareStatement(sql);
        return stmt.executeUpdate();
    }

    public void close(Connection conn, PreparedStatement stmt, ResultSet rs) {
        try {
            if (rs != null) rs.close();
            if (stmt != null) stmt.close();
            if (conn != null) conn.close();
        } catch (SQLException e) {
            e.printStackTrace();
        }
    }

}
