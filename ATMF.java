package atm;
import java.util.Scanner;
public class ATM {
    static String names[] = new String[100];
    static int cardISI[] = new int[100];
    static int passwords[] = new int[100];
    static int inventories[] = new int[100];
    public String name;
    public long ISI;
    public int password;
    public int inventory;

    ATM() {
    }

    ATM(String name, long ISI, int password, int inventory) {
        this.name = name;
        this.ISI = ISI;
        this.password = password;
        this.inventory = inventory;
    }

    void print() {
        System.out.println("نام کاربر:" + name);
        System.out.println("شماره حساب :" + ISI);
        System.out.println("رمژ:" + password);
        System.out.println("موجودی:" + inventory);
    }

    public static void main(String[] args) {
        System.out.println("*****************با سلام لطفا برای ادامه به تعداد دلخواه حساب کاربری ایجاد کنید  **************");
        System.out.println("   *******************   برای ایجاد حساب اژ دستور  sign  استفاده کنید************************* ");
        System.out.println("      *************    برای موجودی حساب خود اژ دستور  mojodi  استفاده کنید  ******************");
        System.out.println("         *************  برای برداشت وجه اژ دستور  bardashtvajh  استفاده کنید  *************");
        System.out.println("            ************** برای انتقال وجه اژ دستور  enteghal  استفاده کنید *********");
        System.out.println("            ************** برای تغییر رمز خود اژ دستور taghir ramz استفاده کنید *********");
        Scanner in = new Scanner(System.in);
        String s = "";
        while (true) {
            s = in.nextLine();
            String cc[] = s.split("  ");
            switch (cc[0]) {
                case "mojodi":
                    if (cc[1].length() == 8 && cc[2].length() == 4) {
                        mojodi(cc[1], cc[2]);
                    }
                    break;

                case "enteghal":
                    if (cc[1].length() == 8 && cc[2].length() == 4 && Integer.parseInt(cc[3]) >= 0) {
                        enteghal(cc[1], cc[2], cc[3], cc[4]);
                    }
                    break;
                case "sign":
                    if (cc[2].length() == 8 && cc[3].length() == 4 && Integer.parseInt(cc[4]) >= 0) {
                        sign(cc[1], cc[2], cc[3], cc[4]);
                    }
                    break;
                case "bardashtvajh":
                    if (cc[1].length() == 8 && cc[2].length() == 4 && Integer.parseInt(cc[3]) >= 0) {
                    bardashtvajh(cc[1], cc[2], cc[3]);
                }
                    break;
                case "taghirramz":
                    if (cc[1].length() == 8 && cc[2].length() == 4 && cc[3].length() == 4 ) {
                        taghirramz(cc[1], cc[2], cc[3]);
                    }
                    break;

            }

        }

    }

    static void bardashtvajh(String isi, String pp, String x) {
        long op = Integer.parseInt(isi);
        int tp = Integer.parseInt(pp);
        int f = Integer.parseInt(x);
        for (int j = 0; j <= 99; j++) {
            if (op == cardISI[j] && tp == passwords[j]) {

                inventories[j] = inventories[j] - f;
                System.out.println("به مقدار" + f + "ریال برداشت شد  " + "موجودی:" + inventories[j]);
            }
        }
    }
    static int i = 0;

    static void sign(String na, String isi, String pp, String mo) {
        ATM y = new ATM();
        names[i] = na;
        cardISI[i] = Integer.parseInt(isi);
        passwords[i] = Integer.parseInt(pp);
        inventories[i] = Integer.parseInt(mo);
        y = new ATM(names[i], cardISI[i], passwords[i], inventories[i]);
        i++;
        y.print();
    }

    static void enteghal(String isi, String pp, String x, String n) {
        long op = Integer.parseInt(isi);
        long oy = Integer.parseInt(n);
        int tp = Integer.parseInt(pp);
        int f = Integer.parseInt(x);
        for (int j = 0; j < 99; j++) {
            if (op == cardISI[j] && tp == passwords[j]) {
                

                
                for (int z = 0; z < 99; z++) {
                    if (oy == cardISI[z]) {
                   
                  Scanner input=new Scanner(System.in);
                  int e;
                                System.out.println(cardISI[z]+names[z]+"آیا اطلاعات برای واریژ وجه درست می باشد");
                                e=input.nextInt();
                                if(e==1){
                        inventories[j] = inventories[j] - f;
                        inventories[z] = inventories[z] + f;
                        System.out.println("به مقدار" + f + "ریال انتقال یافت");
                                }
                    } 
                }

            }
        }
    }

    static void mojodi(String isi, String pp) {
        long op = Integer.parseInt(isi);
        int tp = Integer.parseInt(pp);

        for (int j = 0; j <= 99; j++) {
            if (op == cardISI[j] && tp == passwords[j]) {

                System.out.println(inventories[j] + ":موجودی حساب شما");
            }
        }

    }
    static void taghirramz(String isi, String pp, String uz) {
        long op = Integer.parseInt(isi);
        int tp = Integer.parseInt(pp);
        int l = Integer.parseInt(uz);
        for (int w = 0; w <= 99; w++) {
            if (op == cardISI[w] && tp == passwords[w]) {

                passwords[w] = l;
                System.out.println( "رمژ شما با موفقیت تغییر یافت " );
            }
        }
}}
