package ajou.oop.parkingcenter;
import javax.swing.*;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;

public class incomeframe extends Frame{
	private JFrame incomeframe;
	private JTextField txtmonth;
	private JTextField txtyear;
	private JLabel lblmonth;
	private JLabel lblday;
	private final JPanel panel = new JPanel();
	private JTextField txtday;
	String year, month, day, T;
	String kind = null;
	String type = null;
	int select, number;

	public incomeframe() {
		initialize();
		incomeframe.setVisible(true);
	}

	private void initialize() {
		incomeframe = new JFrame();
		incomeframe.setTitle("수입보기");
		incomeframe.setBounds(100, 100, 248, 211);
		incomeframe.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		incomeframe.getContentPane().setLayout(null);
		incomeframe.setLocationRelativeTo(null);
		incomeframe.getContentPane().add(panel);
		panel.setLayout(null);
		
		txtmonth = new JTextField(2);
		txtmonth.setBounds(108, 71, 33, 26);
		panel.add(txtmonth);
		txtmonth.setColumns(10);
		
		JLabel lblenter = new JLabel("날짜입력 (예: 2020년 03월 07일)");
		lblenter.setBounds(30, 31, 185, 16);
		panel.add(lblenter);
		
		txtyear = new JTextField(4);
		txtyear.setBounds(30, 71, 55, 26);
		panel.add(txtyear);
		txtyear.setColumns(10);
		
		JLabel lblyear = new JLabel("년");
		lblyear.setBounds(85, 76, 11, 16);
		panel.add(lblyear);
		
		lblmonth = new JLabel("월");
		lblmonth.setBounds(142, 76, 11, 16);
		panel.add(lblmonth);
		
		lblday = new JLabel("일");
		lblday.setBounds(192, 76, 11, 16);
		panel.add(lblday);
		panel.setBounds(0, 0, 249, 183);
		
		txtday = new JTextField(2);
		txtday.setColumns(10);
		txtday.setBounds(154, 71, 33, 26);
		panel.add(txtday);
		
		JButton btnOK = new JButton("Ok");
		btnOK.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				year = txtyear.getText();
				month = txtmonth.getText();
				day = txtday.getText();
				T = year + " " + month + " " + day + " 00 00";
				Time i = new Time(T);
				if (i.iserror() == 0) {
				if(i.isValid() == false) {
					JOptionPane.showMessageDialog(null," 유효하지 않은 날짜입니다.", "입력 오류", JOptionPane.WARNING_MESSAGE);
				}else
					JOptionPane.showMessageDialog(null, year +"년 "+ month + "월 " + day + " 일 수입\n : [" + p.income(T) + "]원\n");
				}
			}
		});
				
		btnOK.setBounds(30, 125, 93, 29);
		panel.add(btnOK);
		
		JButton btnCancel = new JButton("Cancel");
		btnCancel.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				incomeframe.setVisible(false);
			}
		});
		btnCancel.setBounds(118, 125, 93, 29);
		panel.add(btnCancel);
}
}