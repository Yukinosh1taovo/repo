package com.itheima.demo.a01static;

import java.util.ArrayList;

public class StudentUtil {

    private StudentUtil(){}

    public static int getMaxAverageStudent(ArrayList<Student> list)
    {
        int maxAge = list.get(0).getAge();

        for (int i = 1; i < list.size(); i++) {
            int tempAge = list.get(i).getAge();

            if(tempAge > maxAge)
                maxAge = tempAge;
        }
        return maxAge;
    }


}
