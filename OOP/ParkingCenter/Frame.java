package ajou.oop.parkingcenter;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.*;
import javax.swing.text.NumberFormatter;

public class Frame extends JFrame{
	static String a = "0000 00 00 00 00";
	static Time standard = new Time(a);

	static ParkingCenter p = new ParkingCenter();
	static int N;
	private JFrame frame;
	
	public static void main(String[] args) {
		EventQueue.invokeLater(new Runnable() {
			public void run() {
				try {
					Frame window = new Frame();
					window.frame.setVisible(true);
				} catch (Exception e) {
					e.printStackTrace();
				}
			}
		});
	}

	public Frame() {
		initialize();
	}

	private void initialize() {
		frame = new JFrame();
		frame.setTitle("주차장 관리 프로그램");
		frame.getContentPane().setEnabled(false);
		frame.setBounds(100, 100, 335, 335);
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frame.getContentPane().setLayout(null);
		frame.setResizable(false);
		frame.setLocationRelativeTo(null);
		JPanel btnpanel = new JPanel();
		btnpanel.setVisible(false);
		btnpanel.setBounds(0, 0, 335, 307);
		frame.getContentPane().add(btnpanel);
		btnpanel.setLayout(null);
		JPanel start = new JPanel();
		start.setBounds(0, 0, 335, 307);
		frame.getContentPane().add(start);
		start.setLayout(null);
		
		JLabel lb1 = new JLabel("주차 가능한  최대 차량 대수를 입력하세요.");
		lb1.setBounds(59, 64, 215, 27);
		start.add(lb1);
		
		NumberFormatter nf = new NumberFormatter();
		nf.setValueClass(Integer.class);
		nf.setMinimum(new Integer(1));
		nf.setMaximum(new Integer(999));
		
		JFormattedTextField text = new JFormattedTextField(nf);
		text.setBounds(123, 103, 73, 26);
		text.setHorizontalAlignment(JTextField.CENTER);
		start.add(text);
		
		JButton Ok1btn = new JButton("OK");

		Ok1btn.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				try{
					JOptionPane.showMessageDialog(null, Integer.parseInt(text.getText()) + "칸으로 입력되었습니다.");
					N = Integer.parseInt(text.getText()); 
					start.setVisible(false);
					btnpanel.setVisible(true);

				}
				catch(NumberFormatException n) {
					JOptionPane.showMessageDialog(null, "1~999 사이 정수를 입력하세요.");
				}	
				
			}
		});
		
		Ok1btn.setBounds(133, 152, 53, 29);
		start.add(Ok1btn);
		JButton info = new JButton("주차현황");
		info.setBounds(10, 280, 70, 20);
		btnpanel.add(info);
		info.addActionListener(new ActionListener() {
			@Override
			public void actionPerformed(ActionEvent e) {
				int a = p.How_Many_Cars();
				String hmc = Integer.toString(a);
				JOptionPane.showMessageDialog(null,"총 주차 칸 수: " + N + "\n잔여 주차 칸 수: " + (N - a));
			}
		});
		
		JButton enterbtn = new JButton("입차하기");
		enterbtn.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				enterframe ef = new enterframe();
			}
		});
		enterbtn.setBounds(118, 55, 97, 29);
		btnpanel.add(enterbtn);
		
		JButton leavebtn = new JButton("출차하기");
		leavebtn.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				leaveframe lv = new leaveframe();
			}
		});
		leavebtn.setBounds(118, 88, 97, 29);
		btnpanel.add(leavebtn);
		
		JButton showbtn = new JButton("차량보기");
		showbtn.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				showframe sf = new showframe();
			}
		});
		showbtn.setBounds(118, 122, 97, 29);
		btnpanel.add(showbtn);
		
		JButton listbtn = new JButton("주차리스트");
		listbtn.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				listframe lf = new listframe();
			}
		});
		
		listbtn.setBounds(118, 157, 97, 29);
		btnpanel.add(listbtn);
		
		JButton incomebtn = new JButton("수입보기");
		incomebtn.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				incomeframe icf = new incomeframe();
			}
		});
		incomebtn.setBounds(118, 191, 97, 29);
		btnpanel.add(incomebtn);
		}
	class JMenuEx extends JFrame{
	    JMenuEx(){
	        this.setTitle("메뉴바 만들기 예제");
	        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	        
	        JMenuBar menuBar = new JMenuBar();
	        JMenu f = new JMenu("File");
	        
	        f.add(new JMenuItem("New"));
	        f.add(new JMenuItem("Open"));
	        f.addSeparator();//분리선 삽입
	        f.add(new JMenuItem("Save"));
	        f.add(new JMenuItem("SaveAs"));
	        
	        menuBar.add(f);
	        this.setJMenuBar(menuBar);
	        
	        this.setLocationRelativeTo(null);
	        this.setSize(300, 200);
	        this.setVisible(false);
	    }
	}


}
