package ajou.oop.parkingcenter;

import javax.swing.JOptionPane;

public class GasolineCar extends Car{
	private int basic_fee, add_fee, basic_time, add_time;
	private int select;
	public GasolineCar(String kind, int number, String datetime, int select){
		super(kind, number, datetime, select);
		this.select = select;
		super.setgroup(1);
		if(select < 1000) {  //경차
			basic_fee = 250;
			add_fee = 50;
			basic_time = 30;
		}
		else {                     //일반승용차
			basic_fee = 500;
			add_fee = 100;
			basic_time = 30;
		}
	}

	@Override
	public long finalfee(){
		return super.getfee(basic_fee, add_fee, basic_time, add_time);
	}
	public int getdp() {
		return select;
	}
	@Override
	public void printParkTime() {
		JOptionPane.showMessageDialog(null,"주차요금(" + super.getnumber() + "번): " + finalfee() + "원 (주차시간 " + super.gethour() + "시간 " + super.getmin() + "분)");
	}
	@Override
	public String special(Time t1, Time t2) {
		return "배기량: " + getdp() + "cc";
	}
}

