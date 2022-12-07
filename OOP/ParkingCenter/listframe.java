package ajou.oop.parkingcenter;
import javax.swing.*;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;

public class listframe extends Frame{

	private JFrame listframe;
	private JTextField txtmonth;
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
	
	public listframe() {
		initialize();
		listframe.setVisible(true);
	}

	private void initialize() {
		listframe = new JFrame();
		listframe.setTitle("주차리스트");
		listframe.setBounds(100, 100, 355, 208);
		listframe.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		listframe.setLocationRelativeTo(null);
		listframe.getContentPane().setLayout(null);
		listframe.getContentPane().add(panel);
		panel.setLayout(null);
		
		txtmonth = new JTextField(2);
		txtmonth.setBounds(110, 65, 33, 26);
		panel.add(txtmonth);
		txtmonth.setColumns(10);
		
		JLabel lblenter = new JLabel("시간입력 (예: 2020년 03월 07일 09시 15분)");
		lblenter.setBounds(32, 37, 253, 16);
		panel.add(lblenter);
		
		txtyear = new JTextField(4);
		txtyear.setBounds(32, 65, 55, 26);
		panel.add(txtyear);
		txtyear.setColumns(10);
		
		JLabel lblyear = new JLabel("년");
		lblyear.setBounds(87, 70, 11, 16);
		panel.add(lblyear);
		
		lblmonth = new JLabel("월");
		lblmonth.setBounds(144, 70, 11, 16);
		panel.add(lblmonth);
		
		lblday = new JLabel("일");
		lblday.setBounds(199, 70, 11, 16);
		panel.add(lblday);
		
		lblhour = new JLabel("시");
		lblhour.setBounds(249, 70, 11, 16);
		panel.add(lblhour);
		
		lblmin = new JLabel("분");
		lblmin.setBounds(304, 70, 11, 16);
		panel.add(lblmin);
		panel.setBounds(0, 0, 355, 179);
		
		txtday = new JTextField(2);
		txtday.setColumns(10);
		txtday.setBounds(164, 65, 33, 26);
		panel.add(txtday);
		
		txthour = new JTextField(2);
		txthour.setColumns(10);
		txthour.setBounds(214, 65, 33, 26);
		panel.add(txthour);
		
		txtmin = new JTextField(2);
		txtmin.setColumns(1);
		txtmin.setBounds(269, 65, 33, 26);
		panel.add(txtmin);
		
		JButton btnOK = new JButton("Ok");
		btnOK.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				year = txtyear.getText();
				month = txtmonth.getText();
				day = txtday.getText();
				hour = txthour.getText();
				minute = txtmin.getText();
				T = year + " " + month + " " + day + " " + hour + " " + minute;
				
				if (p.How_Many_Cars() == 0) {
					JOptionPane.showMessageDialog(null, "주차장에 주차한 차량이 존재하지 않습니다.", "입력 오류", JOptionPane.WARNING_MESSAGE);
				} else {
					if (txtyear.equals("") == false && txtmonth.equals("") == false && txtday.equals("") == false
							&& txthour.equals("") == false && txtmin.equals("") == false) {
						Time l = new Time(T);
					

						if (l.iserror() == 0) {
							if (l.isValid() == false) {
								JOptionPane.showMessageDialog(null, "존재하지 않는 날짜입니다. 다시 입력하세요.", "입력 오류", JOptionPane.WARNING_MESSAGE);
							} else if (standard.calcul(l) <= 0) {
								 JOptionPane.showMessageDialog(null, "이전 명령보다 늦은 시간으로 입력해 주세요.", "입력 오류", JOptionPane.WARNING_MESSAGE);
								 
							} else {
								standard = l;
								p.list(l);
								JOptionPane.showMessageDialog(null, p.getlist(l));
								
				listframe.setVisible(false);
			
			}
			}
					}
				}
			}
		});
		btnOK.setBounds(79, 113, 93, 29);
		panel.add(btnOK);
		
		JButton btnCancel = new JButton("Cancel");
		btnCancel.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				listframe.setVisible(false);
			}
		});
		btnCancel.setBounds(174, 113, 93, 29);
		panel.add(btnCancel);
	}
}

