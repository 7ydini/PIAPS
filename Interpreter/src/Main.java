import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class Main {
    public static void main(String[] args) {
        EventQueue.invokeLater(new Runnable() {
            public void run() {
                GUI window = new GUI();
            }
        });
    }
}
class GUI{
    JFrame frame = new JFrame("Interpreter");
    JTextField text = new JTextField();
    JLabel label = new JLabel("");
    JLabel textLabel = new JLabel();
    JButton button = new JButton("Send");
    GUI(){
        frame.setSize(600, 400);
        frame.setResizable(false);
        frame.setLayout(null);
        frame.setVisible(true);
        text.setBounds(10, 10, 400, 100);
        textLabel.setBounds(10, 110, 400, 300);
        button.setBounds(420, 10, 100, 100);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.add(text);
        frame.add(textLabel);
        frame.add(button);

        frame.repaint();
        button.addActionListener(new Send());
    }
    private class Send implements ActionListener {
        @Override
        public void actionPerformed(ActionEvent e) {
            String context = text.getText();
            AbstractExpression ae = new AbstractExpression();
            textLabel.setText(ae.interpret(context));
            frame.repaint();
        }
    }
}
