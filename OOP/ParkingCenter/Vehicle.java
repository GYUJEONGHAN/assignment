package ajou.oop.parkingcenter;

public abstract class Vehicle implements Comparable<Vehicle>{
	private String kind;
	private String dt;
	private int number;
	private Time intime, outtime;
	private long p_time;
	private long fee;
	private long h, m;
	private int group;
	private int select;
	public Vehicle(String kind, int number, String datetime, int select) {
		this.kind = kind;
		this.number = number;
		dt = datetime;
		intime = new Time(datetime);
	}
	public String getchange(){
        int index = 10;
        String newString = getdatetime().substring(0, index) + " 00 00";
        return newString;
	}
	public String getdatetime() {
		return dt;
	}
	public void setdatetime(String dt) {
		this.dt = dt;
	}
	public abstract String special(Time t1, Time t2);
	
	public abstract long finalfee();
	
	public long getptime() {
		p_time = intime.calcul(outtime); //출차 - 입차
		return p_time;
	}
	public int getselect() {
		return select;
	}
	
	public long getfee(int bf, int af, int bt, int at) {
		long addfeetime = getptime() - bt; //추가시간
		long addfee; //추가요금
		if(getptime() <= bt) { //기본시간보다 주차시간이 작거나 같을 때 (Car만 해당)
			fee = bf;
			if(getptime() == 0) fee = 0;
		}
		else {
			if(getptime() % 10 == 0) {
				addfee = (addfeetime / 10) * af; //주차시간이 10단위로 끝날때 (10,20,30..)
			fee = addfee + bf;
			}
			else addfee = ((addfeetime / 10) + 1) * af; //위 경우가 아닐 때 (예: 32->40 , 59->60 변환)
			fee = addfee + bf;
		}
		return fee;
	}
	
	public void printParkTime() {
	}
	public long gethour() {
		h = getptime() / 60;
		return h;
	}
	
	public long getmin() {
		if(h == 0) {
			m = getptime();
		}
		else m = getptime() - h * 60;
		return m;
	}
	
	public String getkind() {
		return kind;
	}
	
	public int getnumber() {
		return number;
	}
	
	public Time getintime() {
		return intime;
	}
	public void setouttime(String outtimestr) {
		outtime = new Time(outtimestr);
	}
	public Time getouttime() {
		return outtime;
	}
	
	public void setgroup(int group) {
		this.group = group;
	}

	public int compareTo(Vehicle other)
	{
		if(this.group!=other.group)
		{return this.group - other.group;}
		else this.intime.calcul(other.intime);
		return 0;
	 }
}