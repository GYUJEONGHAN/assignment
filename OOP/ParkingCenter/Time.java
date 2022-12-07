package ajou.oop.parkingcenter;
import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.GregorianCalendar;

import javax.swing.JOptionPane;

public class Time {
	private String datestr;
	private SimpleDateFormat Format = new SimpleDateFormat("yyyy MM dd HH mm");
	private SimpleDateFormat Format2 = new SimpleDateFormat("yyyy-MM-dd HH:mm");
	private Date date;
	private long times;
	private int error = 0;
	
	public Time(String datestr){
		this.datestr = datestr;
		try {
			date = Format.parse(datestr);
			times = date.getTime();
		} catch (ParseException e) {
			JOptionPane.showMessageDialog(null,"잘못된 날짜 형식입니다. YYYY MM DD HH mm 형식으로 공백 없이 입력하십시오.");
			error = 1;
		}
	}

	public String invert() {
		String dateToStr = Format2.format(date);
		return dateToStr;
	}
	
	public int iserror() {
		return error;
	}
	
	public  boolean isValid() {
		int limit;
		String[] str = datestr.split(" ");
		int yy = Integer.parseInt(str[0]);
		int mm = Integer.parseInt(str[1]);
		int dd = Integer.parseInt(str[2]);
		int hour = Integer.parseInt(str[3]);
		int min = Integer.parseInt(str[4]);
		
		GregorianCalendar gregori = new GregorianCalendar();
		
		if(mm == 2) {
			if(gregori.isLeapYear(yy)) limit = 29;
			else limit = 28;
		}
		else if(mm == 1 || mm == 3 || mm == 5 || mm == 7 || mm == 8 || mm == 10 || mm == 12) limit = 31;
		else limit = 30;
		
		if(dd > limit || mm > 12) return false;
		else if(hour > 23 || min > 59) return false; 
		else return true;
	}
	
	public long calcul(Time other) {
		long diff;
		
		diff = (other.times - this.times) / 60000;
		return diff;
	}
	
}

