import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class SimpleCalculator extends JFrame implements ActionListener {
    private JTextField display;
    private double firstNumber = 0;
    private double secondNumber = 0;
    private String operator = "";
    private boolean startNewNumber = true;

    public SimpleCalculator() {
        setTitle("Calculator");
        setSize(400, 500);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLocationRelativeTo(null);

        display = new JTextField("0");
        display.setHorizontalAlignment(JTextField.RIGHT);
        display.setEditable(false);
        display.setFont(new Font("Arial", Font.PLAIN, 24));

        JPanel buttonPanel = new JPanel();
        buttonPanel.setLayout(new GridLayout(4, 4, 10, 10));

        String[] buttonLabels = {
                "7", "8", "9", "/",
                "4", "5", "6", "*",
                "1", "2", "3", "-",
                "0", ".", "=", "+"
        };

        for (String label : buttonLabels) {
            JButton button = new JButton(label);
            button.setFont(new Font("Arial", Font.PLAIN, 24));
            button.addActionListener(this);
            buttonPanel.add(button);
        }

        getContentPane().add(display, BorderLayout.NORTH);
        getContentPane().add(buttonPanel, BorderLayout.CENTER);
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        String command = e.getActionCommand();

        if (command.chars().allMatch(Character::isDigit) || command.equals(".")) {
            if (startNewNumber) {
                display.setText(command.equals(".") ? "0." : command);
                startNewNumber = false;
            } else {
                display.setText(display.getText() + command);
            }
        } else {
            if (command.equals("=")) {
                if (!operator.isEmpty()) {
                    secondNumber = Double.parseDouble(display.getText());
                    double result = calculate(firstNumber, secondNumber, operator);
                    display.setText(String.valueOf(result));
                    operator = "";
                    startNewNumber = true;
                }
            } else {
                firstNumber = Double.parseDouble(display.getText());
                operator = command;
                startNewNumber = true;
            }
        }
    }

    private double calculate(double num1, double num2, String operator) {
        switch (operator) {
            case "+":
                return num1 + num2;
            case "-":
                return num1 - num2;
            case "*":
                return num1 * num2;
            case "/":
                return num1 / num2;
            default:
                return 0;
        }
    }

    public static void main(String[] args) {
        SwingUtilities.invokeLater(() -> {
            SimpleCalculator calculator = new SimpleCalculator();
            calculator.setVisible(true);
        });
    }
}
