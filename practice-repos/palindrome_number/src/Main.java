package src;

import java.util.Scanner;

public class Main {

    public static void main(String[] args) {

        Scanner scanner = new Scanner(System.in);

        System.out.print("请输入一个三位数:");
        int num = scanner.nextInt();

        if(num < 100 || num >= 1000) {
            System.out.println("输入的数字应为三位数");
            return;
        }

        int[] numArray = new int[3];
        int temp = num;
        for(int i=2; i>=0; i--) {
            numArray[i] = temp % 10;
            temp /= 10;
        }

        boolean isPalindrome = true;
        for(int i=0; i<numArray.length/2; i++) {
            if(numArray[i] != numArray[numArray.length-1-i]) {
                isPalindrome = false;
                break;
            }
        }

        if(isPalindrome) {
            System.out.println(num + " 是一个回文数");
        } else {
            System.out.println(num + " 不是一个回文数");
        }

    }

}