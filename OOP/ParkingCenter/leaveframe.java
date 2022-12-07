package ajou.oop.parkingcenter;

import javax.swing.*;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;

public class leaveframe extends Frame {

	private JFrame leaveframe;
	private JTextField txtmonth;
	private JTextField txtnum;
	private JTextField txtyear;
	private JLabel lblmonth;
	private JLabel lblday;
	private JLabel lblhour;
	private JLabel lblmin;
	private final JPanel panel = new JPanel();
	private JTextField txtday;
	private JTextField txthour;
	private JTextField txtmin;
	String year, month, day, hour, minute, T;
	String kind = null;
	String type = null;
	int select, number;

	public leaveframe() {
		initialize();
		leaveframe.setVisible(true);
	}

	private void initialize() {
		leaveframe = new JFrame();
		leaveframe.setTitle("출차하기");
		leaveframe.setBounds(100, 100, 385, 278);
		leaveframe.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		leaveframe.setLocationRelativeTo(null);
		leaveframe.getContentPane().setLayout(null);
		leaveframe.getContentPane().add(panel);
		panel.setLayout(null);

		JLabel lblnum = new JLabel("차량번호");
		lblnum.setBounds(129, 48, 44, 16);
		panel.add(lblnum);

		txtnum = new JTextField(4);
		txtnum.setBounds(177, 43, 76, 26);
		panel.add(txtnum);
		txtnum.setColumns(10);

		txtmonth = new JTextField(2);
		txtmonth.setBounds(129, 114, 33, 26);
		panel.add(txtmonth);
		txtmonth.setColumns(10);

		JLabel lblenter = new JLabel("출차시간 (예: 2020년 03월 07일 09시 15분)");
		lblenter.setBounds(52, 86, 253, 16);
		panel.add(lblenter);

		txtyear = new JTextField(4);
		txtyear.setBounds(52, 114, 55, 26);
		panel.add(txtyear);
		txtyear.setColumns(10);

		JLabel lblyear = new JLabel("년");
		lblyear.setBounds(107, 119, 11, 16);
		panel.add(lblyear);

		lblmonth = new JLabel("월");
		lblmonth.setBounds(161, 119, 11, 16);
		panel.add(lblmonth);

		lblday = new JLabel("일");
		lblday.setBounds(214, 119, 11, 16);
		panel.add(lblday);

		lblhour = new JLabel("시");
		lblhour.setBounds(269, 119, 11, 16);
		panel.add(lblhour);

		lblmin = new JLabel("분");
		lblmin.setBounds(319, 119, 11, 16);
		panel.add(lblmin);
		panel.setBounds(0, 0, 385, 250);

		txtday = new JTextField(2);
		txtday.setColumns(10);
		txtday.setBounds(182, 114, 33, 26);
		panel.add(txtday);

		txthour = new JTextField(2);
		txthour.setColumns(10);
		txthour.setBounds(237, 114, 33, 26);
		panel.add(txthour);

		txtmin = new JTextField(2);
		txtmin.setColumns(1);
		txtmin.setBounds(285, 114, 33, 26);
		panel.add(txtmin);

		JButton btnOK = new JButton("Ok");
		btnOK.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				number = Integer.parseInt(txtnum.getText());
				year = txtyear.getText();
				month = txtmonth.getText();
				day = txtday.getText();
				hour = txthour.getText();
				minute = txtmin.getText();
				T = year + " " + month + " " + day + " " + hour + " " + minute;

				if (p.How_Many_Cars() == 0) {
					JOptionPane.showMessageDialog(null, "주차장에 주차한 차량이 존재하지 않습니다.", "입력 오류", JOptionPane.WARNING_MESSAGE);
				} // else {
				else if (number < 0 || number > 9999) {
					JOptionPane.showMessageDialog(null, "차량번호는 네자리 정수만 가능합니다.", "입력 오류", JOptionPane.WARNING_MESSAGE);
				} else if (p.findcar(number) == 0) {
					JOptionPane.showMessageDialog(null, "주차장에 존재하지 않는 차량입니다.", "입력 오류", JOptionPane.WARNING_MESSAGE);
				} else {
					if (txtyear.equals("") == false && txtmonth.equals("") == false && txtday.equals("") == false
							&& txthour.equals("") == false && txtmin.equals("") == false) {
						Time b = new Time(T);
						int index = 0;
						index = p.get_index();
						Vehicle leaveCar = p.getcar(index);

						if (b.iserror() == 0) {
							if (b.isValid() == false) {
								JOptionPane.showMessageDialog(null, "존재하지 않는 날짜입니다. 다시 입력하세요.", "입력 오류", JOptionPane.WARNING_MESSAGE);
							} else if (b.calcul(leaveCar.getintime()) >= 0) {
								JOptionPane.showMessageDialog(null, "출차시간을 입차시간보다 뒤로 설정해 주세요.", "입력 오류", JOptionPane.WARNING_MESSAGE);
							} else if (standard.calcul(b) <= 0) {
								 JOptionPane.showMessageDialog(null, "이전 명령보다 늦은 시간으로 입력해 주세요.", "입력 오류", JOptionPane.WARNING_MESSAGE);
								 
							} else {
								standard = b;
								leaveCar.setouttime(T);
								leaveCar.printParkTime();
								p.outcar(leaveCar);

								leaveCar.setdatetime(T);
								leaveCar.setdatetime(leaveCar.getchange());
								p.addleave(leaveCar);
								leaveframe.setVisible(false);
							}
						}

					}
				}
			}

		});
		btnOK.setBounds(94, 195, 93, 29);
		panel.add(btnOK);

		JButton btnCancel = new JButton("Cancel");
		btnCancel.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				leaveframe.setVisible(false);
			}
		});
		btnCancel.setBounds(192, 195, 93, 29);
		panel.add(btnCancel);
	}
}
