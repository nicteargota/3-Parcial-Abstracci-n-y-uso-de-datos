import java.io.OutputStreamWriter;
import java.io.FileOutputStream;
import java.nio.charset.StandardCharsets;
import java.util.ArrayList;
import java.util.Scanner;

class Carro {

    String marca;
    String color;

    Carro(String marca, String color) {
        this.marca = marca;
        this.color = color;
    }
}

public class ListaJSON {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        try {

            ArrayList<Carro> lista = new ArrayList<>();

            for (int i = 1; i <= 3; i++) {

                System.out.println("Carro " + i);

                System.out.print("Marca: ");
                String marca = sc.nextLine();

                System.out.print("Color: ");
                String color = sc.nextLine();

                lista.add(new Carro(marca, color));
            }

            OutputStreamWriter archivo =
                    new OutputStreamWriter(
                            new FileOutputStream("lista.json"),
                            StandardCharsets.UTF_8);

            archivo.write("{\n");
            archivo.write("  \"carros\": [\n");

            for (int i = 0; i < lista.size(); i++) {

                Carro c = lista.get(i);

                archivo.write("    {\n");
                archivo.write("      \"marca\": \"" + c.marca + "\",\n");
                archivo.write("      \"color\": \"" + c.color + "\"\n");
                archivo.write("    }");

                if (i < lista.size() - 1) {
                    archivo.write(",");
                }

                archivo.write("\n");
            }

            archivo.write("  ]\n");
            archivo.write("}");

            archivo.close();

            System.out.println("Archivo JSON creado");

        } catch (Exception e) {
            System.out.println("Error");
        }
    }
}
