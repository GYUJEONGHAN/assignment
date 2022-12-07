package ajou.oop.parkingcenter;
import java.util.Collections;
import javax.swing.JOptionPane;
import java.util.ArrayList;
public class ParkingCenter {
	private ArrayList<Vehicle> vehicles = new ArrayList<Vehicle>();
	private ArrayList<Vehicle> leavelist = new ArrayList<Vehicle>();
	private ArrayList<Vehicle> outvec = new ArrayList<Vehicle>();
	private int index;
	public ParkingCenter() {};
	
	public int How_Many_Cars() {
		return vehicles.size();
	}
	
	public void incar(Vehicle v) {
		vehicles.add(v);
	}
	public void addleave(Vehicle v) {
		leavelist.add(v);
	}
	public void reincar(Vehicle v) {
		vehicles.add(v);
		outvec.remove(index);
		index = 0;
	}
	public void outcar(Vehicle v) {
		vehicles.remove(index);
		index = 0;
		outvec.add(v);
	}
	public int findcar(int number) {
		int k=0;
		for(int i=0; i<vehicles.size();i++) {
			if(number == vehicles.get(i).getnumber()) {
				k = 1;
				index = i;
			}
		}
		return k;
	}
	
	public int isreturncar(int number) {
		int k=0;
		for(int i=0; i<outvec.size();i++) {
			if(number == outvec.get(i).getnumber()) {
				k = 1;
				index = i;
			}
		}
		return k;
	}
	
	public int get_index() {
		return index;
	}
	
	public Vehicle getcar(int index) {
		return vehicles.get(index);
	}
	
	public Vehicle getreturncar(int index) {
		return outvec.get(index);
	}
	
	public void show(Time t, Vehicle c) {
		JOptionPane.showMessageDialog(null,("[" + c.getnumber() + "번] "
	+ c.getkind() + " / 입차시간: " + c.getintime().invert() + " / " +
	 c.special(t, c.getintime())));
	}

	private ArrayList<String> str = new ArrayList<String>();
	
	public void list(Time t){
		Collections.sort(vehicles);
		for(Vehicle cars : vehicles) {
		            str.add("[" + cars.getnumber() + "번] " +
					cars.getkind() + " / 입차시간: " + cars.getintime().invert() + " / " +
					cars.special(t, cars.getintime()) + "\n");
			}
		}
	public String getlist(Time t) {
		String a = "";
		for (String lst : str) {
			a+= lst;
		}
		return "- " + t.invert() + " 기준 주차차량 리스트 -\n" + a;
	}
	
	public int income(String s) {
		int k = 0;
		for(Vehicle c : leavelist) {
			if(s.equals(c.getchange())) {
				k += (int)c.finalfee();
			}
		}
		return k;
	}
}