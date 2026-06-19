import java.io.FileWriter;
import java.util.Scanner;

public class Codigo2CSV {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        try {

            FileWriter archivo = new FileWriter("suma.csv");

            int x, y;

            System.out.print("Ingresa un numero: ");
            x = sc.nextInt();

            System.out.print("Ingresa otro numero: ");
            y = sc.nextInt();

            int suma = x + y;

            archivo.write("Numero1,Numero2,Suma\n");
            archivo.write(x + "," + y + "," + suma);

            archivo.close();

            System.out.println("Archivo CSV creado");

        } catch (Exception e) {
            System.out.println("Error");
        }

        sc.close();
    }
}
