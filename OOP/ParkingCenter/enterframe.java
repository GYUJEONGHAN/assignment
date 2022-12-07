package ajou.oop.parkingcenter;

import javax.swing.*;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;

public class enterframe extends Frame {
	private JFrame enterframe;
	private JTextField txtmonth;
	private JTextField txtnum;
	private JTextField txtyear;
	private JLabel lblmonth;
	private JLabel lblday;
	private JLabel lblhour;
	private JLabel lblmin;
	private final JPanel panel = new JPanel();
	private JTextField txtsel;
	private JTextField txtday;
	private JTextField txthour;
	private JTextField txtmin;

	public enterframe() {
		initialize();
		enterframe.setVisible(true);
	}

	private void initialize() {
		enterframe = new JFrame();
		enterframe.setTitle("입차하기");
		enterframe.setBounds(100, 100, 385, 278);
		enterframe.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	    enterframe.setLocationRelativeTo(null);
		enterframe.getContentPane().setLayout(null);
		enterframe.getContentPane().add(panel);
		panel.setLayout(null);

		JRadioButton kind1 = new JRadioButton("가솔린차");
		kind1.setBounds(84, 6, 76, 23);
		panel.add(kind1);

		JRadioButton kind2 = new JRadioButton("전기차");
		kind2.setBounds(157, 6, 65, 23);
		panel.add(kind2);

		JRadioButton kind3 = new JRadioButton("벤");
		kind3.setBounds(222, 6, 43, 23);
		panel.add(kind3);
		ButtonGroup kindselect = new ButtonGroup();
		kindselect.add(kind1);
		kindselect.add(kind2);
		kindselect.add(kind3);

		JLabel lblnum = new JLabel("차량번호");
		lblnum.setBounds(129, 41, 44, 16);
		panel.add(lblnum);

		txtnum = new JTextField(4);
		txtnum.setBounds(182, 36, 76, 26);
		panel.add(txtnum);
		txtnum.setColumns(10);

		JLabel lblsel = new JLabel("선택사항(배기량/충전량/크기)");
		lblsel.setBounds(23, 69, 154, 16);
		panel.add(lblsel);

		txtmonth = new JTextField(2);
		txtmonth.setBounds(129, 150, 33, 26);
		panel.add(txtmonth);
		txtmonth.setColumns(10);

		JLabel lblenter = new JLabel("입차시간 (예: 2020년 03월 07일 09시 15분)");
		lblenter.setBounds(53, 122, 253, 16);
		panel.add(lblenter);

		txtyear = new JTextField(4);
		txtyear.setBounds(53, 150, 55, 26);
		panel.add(txtyear);
		txtyear.setColumns(10);

		JLabel lblyear = new JLabel("년");
		lblyear.setBounds(108, 155, 11, 16);
		panel.add(lblyear);

		lblmonth = new JLabel("월");
		lblmonth.setBounds(162, 155, 11, 16);
		panel.add(lblmonth);

		lblday = new JLabel("일");
		lblday.setBounds(218, 155, 11, 16);
		panel.add(lblday);

		lblhour = new JLabel("시");
		lblhour.setBounds(274, 155, 11, 16);
		panel.add(lblhour);

		lblmin = new JLabel("분");
		lblmin.setBounds(319, 155, 11, 16);
		panel.add(lblmin);
		panel.setBounds(0, 0, 385, 250);

		txtsel = new JTextField(5);
		txtsel.setColumns(10);
		txtsel.setBounds(182, 67, 76, 26);
		panel.add(txtsel);

		txtday = new JTextField(2);
		txtday.setColumns(10);
		txtday.setBounds(182, 150, 33, 26);
		panel.add(txtday);

		txthour = new JTextField(2);
		txthour.setColumns(10);
		txthour.setBounds(241, 150, 33, 26);
		panel.add(txthour);

		txtmin = new JTextField(2);
		txtmin.setColumns(1);
		txtmin.setBounds(286, 150, 33, 26);
		panel.add(txtmin);

		// OK , Cancel 버튼
		JButton btnOK = new JButton("Ok");
		btnOK.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				String year, month, day, hour, minute, T;
				String kind = null;
				String type = null;
				int select, number;

				if (kind1.isSelected())
					kind = "g";
				else if (kind2.isSelected())
					kind = "e";
				else if (kind3.isSelected())
					kind = "v";

				number = Integer.parseInt(txtnum.getText());
				year = txtyear.getText();
				month = txtmonth.getText();
				day = txtday.getText();
				hour = txthour.getText();
				minute = txtmin.getText();
				select = Integer.parseInt(txtsel.getText());
				T = year + " " + month + " " + day + " " + hour + " " + minute;
				Time f = new Time(T);

				

	
				String strInteger = txtsel.getText();
				if(p.How_Many_Cars() == N) {
					JOptionPane.showMessageDialog(null, "주차 공간이 부족합니다.", "입력 오류", JOptionPane.WARNING_MESSAGE);
				} else {
					if (kind.equals("g") && select < 0) {
						JOptionPane.showMessageDialog(null, "배기량은 음수일 수 없습니다.", "입력 오류", JOptionPane.WARNING_MESSAGE);
					} else if (kind.equals("e") && (select < 0 || select > 60)) {
						JOptionPane.showMessageDialog(null, "전기차의 충전량을 0~60 사이로 입력하세요.", "입력 오류", JOptionPane.WARNING_MESSAGE);
					} else if (kind.equals("v") && (select < 1 || select > 3)) {
						JOptionPane.showMessageDialog(null, "벤의 크기를 1~3 사이로 입력하세요.", "입력 오류", JOptionPane.WARNING_MESSAGE);
					} else {
						if (p.findcar(number) == 1) {
							JOptionPane.showMessageDialog(null, "이미 주차중인 차량의 번호를 입력했습니다.", "입력 오류", JOptionPane.WARNING_MESSAGE);
						} else if (p.isreturncar(number) == 1) {
							int index = p.get_index();
							Vehicle c = p.getreturncar(index);
							if (!kind.equals(c.getkind()) && select != c.getselect())
								JOptionPane.showMessageDialog(null, "출차차량과 같은 번호, 다른 차량입니다.", "입력 오류", JOptionPane.WARNING_MESSAGE);
						} else {
							if(txtyear.equals("") == false && txtmonth.equals("") == false 
									&& txtday.equals("") == false && txthour.equals("") == false 
									&& txtmin.equals("") == false) {
							if (f.iserror() == 0) {
								if (f.isValid() == false) {
									JOptionPane.showMessageDialog(null, "존재하지 않는 날짜입니다. 다시 입력하세요.", "입력 오류", JOptionPane.WARNING_MESSAGE);
								}
							else if (standard.calcul(f) <= 0) {
								JOptionPane.showMessageDialog(null, "이전 명령보다 늦은 시간으로 입력해 주세요.", "입력 오류", JOptionPane.WARNING_MESSAGE);}
							else {
								Vehicle enterCar;
								if (kind.equals("g")) {
									if (select < 1000)
										type = "경차";
									else
										type = "일반승용차";
									enterCar = new GasolineCar(type, number, T, select);
									p.incar(enterCar);
								} else if (kind.equals("e")) {
									type = "전기차";
									enterCar = new ElectricCar(type, number, T, select);
									p.incar(enterCar);
								} else if (kind.equals("v")) {
									type = "벤";
									enterCar = new Van(type, number, T, select);
									p.incar(enterCar);
								}
								JOptionPane.showMessageDialog(null,
										type + " 차량 1대가 주차장에 입차 되었습니다. [차량번호: " + number + "]");
								standard = f;
								enterframe.setVisible(false);
							}
						}
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
				enterframe.setVisible(false);
			}
		});
		btnCancel.setBounds(192, 195, 93, 29);
		panel.add(btnCancel);
	}
}
