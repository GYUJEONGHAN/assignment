package ajou.oop.parkingcenter;

import javax.swing.JOptionPane;

public class ElectricCar extends Car{
	private int basic_fee, add_fee, basic_time, add_time;
	private long charge_fee;
	private int select;
	public ElectricCar(String kind, int number, String datetime, int select){
		super(kind, number, datetime, select);
		this.select = select;
		basic_fee = 500;
		add_fee = 100;
		basic_time = 30;
		super.setgroup(2);
		}
	@Override
	public long finalfee(){
		return super.getfee(basic_fee, add_fee, basic_time, add_fee) + getchargefee();
	}
	public long getchargefee() {
	    long t = (60-getcharge())*2; //완충에 필요한 시간
		if(super.getptime() < t) charge_fee = super.getptime() * 200; //완충시간 >= 주차시간일 떄
		else charge_fee =  t * 200;      //완충시간 < 주차시간일 때
		return charge_fee;
	}

	public long getcharge() {
		return select;
	}
	public long aftercharge() {
		long a = getcharge() + (charge_fee / 200 / 2);
		if(a>60) a = 60;
		return a;
	}
	@Override
	public void printParkTime() {
		JOptionPane.showMessageDialog(null, "총요금(" + super.getnumber() + "번): " + finalfee() + "원" + "\n- 주차요금: "+ super.getfee(basic_fee, add_fee, basic_time, add_fee) +"원 (주차시간 " + super.gethour() + "시간 " + super.getmin() + "분)\n- 충전요금 : " + getchargefee() + "원(현재충전량: " + aftercharge()+ "KW)");
	}
	
	@Override
	public String special(Time t1, Time t2) {
		long t = (60-getcharge())*2; //완충에 필요한 시간
		long chrtime = 0;
		if(t2.calcul(t1) < t) chrtime = t2.calcul(t1); //완충시간 >= 주차시간일 떄
		else chrtime =  t;      //완충시간 < 주차시간일 때
		long finalcharge = getcharge() + (chrtime / 2);
		return " 현재 충전량 : " + finalcharge + "Kwh / (입차시 충전량: " + getcharge() + "Kwh, 충전한 양: " + chrtime / 2 + "Kwh)"; 
	}
}
