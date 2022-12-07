package ajou.oop.parkingcenter;

public class Car extends Vehicle {
	private int basic_fee, add_fee, basic_time, add_time;
	public Car(String kind, int number, String datetime, int select) {
		super(kind, number, datetime, select);
		basic_time = 30;
	}

	public long finalfee(){
		return super.getfee(basic_fee, add_fee, basic_time, add_time);
	}
	
	public String special(Time t1, Time t2) {
		return "";
	}
}
