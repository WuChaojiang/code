package Demo;

import java.text.DateFormatSymbols;
import java.util.Calendar;
import java.util.GregorianCalendar;
import java.util.Locale;

public class CalendarDemo {
    private int today;
    private int month;
    private int firstDayOfWeek;
    private GregorianCalendar date;

    public CalendarDemo() {
        Locale.setDefault(Locale.US);

        date = new GregorianCalendar();
        today = date.get(Calendar.DAY_OF_MONTH);
        month = date.get(Calendar.MONDAY);
        firstDayOfWeek = date.getFirstDayOfWeek();
    }

    public void printCalendar() {
        printWeekdaySymbols();

        printEmpytSymbols();

        printDays();
    }

    private void printEmpytSymbols() {
        int interval = getIntervalAtFirstDay();
        for (int i = 0; i < interval; ++i) {
            System.out.print("     ");
        }
    }

    private int getIntervalAtFirstDay() {
        date.set(Calendar.DAY_OF_MONTH, 1);

        int weekday = date.get(Calendar.DAY_OF_WEEK);
        int interval = 0;

        // 根据星期标识作为判断条件
        while(firstDayOfWeek != weekday) {
            date.add(Calendar.DAY_OF_MONTH, -1);
            interval++;
            weekday = date.get(Calendar.DAY_OF_WEEK);
        }
        // 恢复初始时期
        date.add(Calendar.DAY_OF_MONTH, interval);


        return interval;
    }

    private void printWeekdaySymbols() {
        String[] weekDayNames = new DateFormatSymbols().getShortWeekdays();

        int indexDayOfWeek = firstDayOfWeek;
        do {
            System.out.printf("%5s", weekDayNames[indexDayOfWeek]);
            ++indexDayOfWeek;
            if (indexDayOfWeek < weekDayNames.length) {
                continue;
            } else {
                indexDayOfWeek = 1;
            }
        } while (indexDayOfWeek != firstDayOfWeek);
        System.out.println();
    }

    private void printDays() {
        date.set(Calendar.DAY_OF_MONTH, 1);
        boolean star = false;
        do {
            int day = date.get(Calendar.DAY_OF_MONTH);
            System.out.printf(star ? "%4d" : "%5d", day);
            if (day == today) {
                System.out.print('*');
                star = true;
            } else {
                star = false;
            }

            date.add(Calendar.DAY_OF_MONTH, 1);
            if (date.get(Calendar.DAY_OF_WEEK) == firstDayOfWeek) {
                System.out.println();
                star = false;
            }
        } while (date.get(Calendar.MONTH) == month); // 根据月份标识作为判断条件
    }
}
