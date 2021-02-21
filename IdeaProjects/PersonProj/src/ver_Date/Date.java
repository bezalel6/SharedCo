package ver_Date;

import java.util.GregorianCalendar;

public class Date {
    private int day, month, year,monthDays;
    public Date(int day, int month, int year) {
        this.day = day;
        this.month = month;
        this.year = year;
        setMonthDays();
    }

    public Date() {
        GregorianCalendar today = new GregorianCalendar();
        this.day = today.get(GregorianCalendar.DAY_OF_MONTH);
        this.month = today.get(GregorianCalendar.MONTH);
        this.year = today.get(GregorianCalendar.YEAR);
    }

    public Date(Date date)
    {
        this.day = date.getDay();
        this.month = date.getMonth();
        this.year = date.getYear();
        setMonthDays();
    }
    private void setMonthDays() {
        switch(month){
            case 2:{monthDays=28;break;}
            case 4:case 6: case 9:case 11:{monthDays=30;break;}
            default:monthDays=31;
        }
        if(month==2&&year%4==0&&(year%100!=0||year%400==0))
            monthDays = 29;
    }


    public int getDay() {
        return day;
    }

    public void setDay(int day) {
        this.day = day;
    }

    public int getMonth() {
        return month;
    }

    public void setMonth(int month) {
        this.month = month;
    }

    public int getYear() {
        return year;
    }

    public void setYear(int year) {
        this.year = year;
    }

    @Override
    public String toString() {
        return "Date{" +
                "day=" + day +
                ", month=" + month +
                ", year=" + year +
                '}';
    }

    public int compareTo(Date date) {
        if (this.year != date.year)
            return this.year - date.year;
        if (this.month != date.month)
            return this.month - date.month;
        return this.day - date.day;
    }

    public Date getTomorrow()
    {
        if(day==monthDays) {
        if(month==12)
            return new Date(1,1,year+1);
        else return new Date(1,month+1,year);
    }
        return new Date(day+1,month,year);
    }
}
