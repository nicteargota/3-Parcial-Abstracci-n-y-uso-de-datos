import java.io.FileWriter;
import java.util.Scanner;

public class Codigo4JSON {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        try {
            FileWriter archivo = new FileWriter("sumas.json");

            int a, b, c;

            System.out.print("Ingresa el primer numero: ");
            a = sc.nextInt();

            System.out.print("Ingresa el segundo numero: ");
            b = sc.nextInt();

            System.out.print("Ingresa el tercer numero: ");
            c = sc.nextInt();

            archivo.write("{\n");
            archivo.write("\"suma2\":" + (a + b) + ",\n");
            archivo.write("\"suma3\":" + (a + b + c) + "\n");
            archivo.write("}");

            archivo.close();

            System.out.println("JSON creado");

        } catch (Exception e) {
            System.out.println("Error");
        }

        sc.close();
    }
}
