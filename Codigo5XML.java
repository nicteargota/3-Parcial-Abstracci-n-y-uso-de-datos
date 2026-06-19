import java.io.FileWriter;
import java.util.Scanner;

public class Codigo5XML {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        try {

            FileWriter archivo = new FileWriter("calculadora.xml");

            int x, y;

            System.out.print("Ingresa el primer numero: ");
            x = sc.nextInt();

            System.out.print("Ingresa el segundo numero: ");
            y = sc.nextInt();

            archivo.write("<operaciones>\n");
            archivo.write("<suma>" + (x + y) + "</suma>\n");
            archivo.write("<resta>" + (x - y) + "</resta>\n");
            archivo.write("<multiplicacion>" + (x * y) + "</multiplicacion>\n");
            archivo.write("</operaciones>");

            archivo.close();

            System.out.println("XML creado");

        } catch (Exception e) {
            System.out.println("Error");
            e.printStackTrace();
        }

        sc.close();
    }
}
