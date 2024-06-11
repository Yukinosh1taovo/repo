package com.pta.homework.chapter10;

import java.io.*;




    public class Main{
        public static void main(String[] args) throws IOException {
            BufferedReader buf = new BufferedReader(
                    new InputStreamReader(System.in));
            while (true) {
                String str = buf.readLine();
                if (str.equals("quit"))
                    break;
                int x = Integer.parseInt(str);
                System.out.println(x * x);
            }
        }
    }

