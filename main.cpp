#include "Drawer.cpp"
#include "stringAnalyzer.cpp"






int main(){
  /* Drawer drawer; */
  /* drawer.setup(); */
  /* drawer._run("(4+8)-2*5"); */
  string expression;
  cout << "Enter a expression: ";
  cin >> expression;
  bool exit = false;

  int option;
  while(!exit){
    cout << "******************" << endl;
    cout << "* " << expression << "*" <<  endl;
    cout << "******************" << endl;
    cout << "1- Analisis Sintactico en forma de cadena" << endl;
    cout << "2- Analisis Sintactico en forma de arbol" << endl;
    cout << "3- Notacion Postfija \n";
    cout << "4- Borrar Derivacion \n";
    cout << "5- Salir \n";
    cout << "opcion: "; cin >> option; 

    if(option == 1){
      system("clear");
      Drawer drawer;
      string posfix = drawer.infixToPosfix(expression);
      SynAnalyzer a;
      vector<string> result = a.getResult(posfix);
      cout << "EXPRESION" << endl;
      for(string str: result){
	cout << str << endl;
      }
      while(getchar() != '\n');
    }

    else if(option == 2){
      system("clear");
      Drawer drawer;
      drawer.setup();
      drawer._run(expression);
      while(getchar() != '\n');
    }

    else if(option == 3){
      system("clear");
      Drawer drawer;
      string result = drawer.infixToPosfix(expression);
      cout << "Posfix String: " << result << endl;
      while(getchar() != '\n');
    }
    else if(option == 4){
      system("clear");
      cout << "Enter the new expression: ";
      cin >> expression;
      while(getchar() != '\n');
    }
    else {
      exit = true;
    }
  }
}




