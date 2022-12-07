package ajou.oop.parkingcenter;

import javax.swing.JOptionPane;

public class Van extends Vehicle{
	private int basic_fee, add_fee, basic_time, add_time;
	private int select;
	public Van(String kind, int number, String datetime, int select) {
		super(kind, number, datetime, select);
		super.setgroup(3);
		basic_fee = 0;
		basic_time = 0;
		if(select == 3) add_fee = 200;
		else if(select == 2) add_fee  = 300;
		else if(select == 1) add_fee  = 500;
	}
	
	@Override
	public long finalfee(){
		return super.getfee(basic_fee, add_fee, basic_time, add_time);
	}
	
	@Override
	public void printParkTime() {
		JOptionPane.showMessageDialog(null,"주차요금(" + super.getnumber() + "번): " + finalfee() + "원 (주차시간 " + super.gethour() + "시간 " + super.getmin() + "분)");
	}
	@Override
	public String special(Time t1, Time t2) {
		String a;
		if(select == 3) a = "소";
		else if(select == 2) a = "중";
		else a = "대";
		return "차량 크기: " + a;
	}
}
