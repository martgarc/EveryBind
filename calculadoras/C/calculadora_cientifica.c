#include <gtk/gtk.h>
#include <string.h>
#include <math.h>
#include <stdio.h>

GtkWidget *label;
int ops = 0;
char str[20];

static void    operate()
{
	extern char str[20];
	float values[20] = {};
	char operands[20] = "";
	char temp[20] = "";
	int i = 0;
	int j = 0;
	int k = 0;
	int t = 0;

	while (str[i-1] != '=')
	{
		if ((str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/' 
		|| str[i] == '='))
		{
			k = 0;
			while (t < i)
			{
				temp[k] = str[t];
				t++;
				k++;
			}
			values[j] = atof(temp);
			memset(temp, 0, 20);
			if (str[i] != '=')
				operands[j] = str[i];
			j++;
			t++;
		}
		i++;
	}
	operands[j] = '\0';
//values[i] = '\0';
	i = 0;
	while (operands[i])
	{
		if (operands[i] == '*' || operands[i] == '/')
		{
			if (operands[i] == '*')
			{
				values[i] = values[i] * values[i + 1];
				for (j = i + 1; values[j]; j++)
					values[j] = values[j+1];
				for (j = i; operands[j]; j++)
					operands[j] = operands[j+1];
				i--;
			}
			if (operands[i] == '/')
			{
				values[i] = values[i] / values[i + 1];
				for (j = i + 1; values[j]; j++)
					values[j] = values[j+1];
				for (j = i; operands[j]; j++)
					operands[j] = operands[j+1];
				i--;
			}
		}
		i++;
	}

	i = 0;
	while (operands[i])
	{
		if (operands[i] == '+' || operands[i] == '-')
		{
			if (operands[i] == '+')
			{
				values[i] = values[i] + values[i + 1];
				for (j = i + 1; values[j]; j++)
					values[j] = values[j+1];
				for (j = i; operands[j]; j++)
					operands[j] = operands[j+1];
				i--;
			}
			if (operands[i] == '-')
			{
				values[i] = values[i] - values[i + 1];
				for (j = i + 1; values[j]; j++)
					values[j] = values[j+1];
				for (j = i; operands[j]; j++)
					operands[j] = operands[j+1];
				i--;
			}
		}
		i++;
	}

	gcvt(values[0], 17, operands);
	strcpy(str, operands);
}

static void set_text(char *Onscreen_value)
{
	extern GtkWidget *label;
	char fnt[10] = "Arial ";
	char *values[10] = {
	"35", "33", "31", "28", "26", "24", "23", "21", "20", "19"};
	int i = 0;


	if (strlen(Onscreen_value) < 11)
		gtk_label_set_text(GTK_LABEL(label), Onscreen_value);
	else if (strlen(Onscreen_value) < 19)
	{
		strcat(fnt, values[i + (strlen(Onscreen_value) - 10)]);
		gtk_widget_override_font(label,
				pango_font_description_from_string(fnt));
		gtk_label_set_text(GTK_LABEL(label), Onscreen_value);
	}
}

static void    sqexp()
{
	extern GtkWidget *label;
	char strnb[20];
	float nb;

	strcpy(strnb, gtk_label_get_text(GTK_LABEL(label)));
	nb = atof(strnb);
	nb = nb * nb;
	gcvt(nb, 18, strnb);
	set_text(strnb);
}

static void    sqroot()
{
	extern GtkWidget *label;
	char strnb[20];
	double nb;

	strcpy(strnb, gtk_label_get_text(GTK_LABEL(label)));
	nb = atof(strnb);
	nb = sqrt(nb);
	gcvt(nb, 10, strnb);
	set_text(strnb);
}

static void button_clicked(GtkWidget* widget, char* value)
{
	extern GtkWidget *label;
	extern char str[20];
	char Onscreen_value[20];
	char result;
	int number;
	extern int ops;
	int a;
	int b;
	int i = 0;

	strcpy(Onscreen_value, gtk_label_get_text(GTK_LABEL(label)));
	if (strcmp(value, "=") != 0 && strcmp(value, "AC") != 0)
	{
		if (strcmp(Onscreen_value, "0") == 0)
		{
			set_text(value);
		}
		else
		{
			if (strcmp(value, "+") == 0 || strcmp(value, "-") == 0 ||
				strcmp(value, "*") == 0 || strcmp(value, "/") == 0)
			{
				if (ops == 0)
				{
					ops = 1;
					strcat(Onscreen_value, value);
					set_text(Onscreen_value);
				}
			}
			else
			{
				ops = 0;
				strcat(Onscreen_value, value);
				set_text(Onscreen_value);
			}
		}
	}
	else if (strcmp(value, "AC") == 0)
	{
		strcpy(Onscreen_value, "0");
		set_text(Onscreen_value);
		gtk_widget_override_font(label, 
			pango_font_description_from_string("Arial 37"));
	}
	else if (strcmp(value, "√") == 0)
	{
		
	}
	else if (strcmp(value, "x²") == 0)
	{
		strcpy(str, Onscreen_value);
		operate();
		sqexp();
		set_text(str);
	}
	else if (strcmp(value, "=") == 0)
	{
		if (Onscreen_value[0] != '-')
			strcpy(str, Onscreen_value);
		else
		{
			strcpy(str, "0");
			strcat(str, Onscreen_value);
		}
		strcat(str, "=");
		operate();
		set_text(str);
	}
}




int main(int argc, char* argv[])
{
	gtk_init(&argc, &argv);

	GtkWidget *window;
	extern GtkWidget *label;
	GtkWidget *table;
	GtkWidget *button;

	char *values[16] = {
	"7", "8", "9", "/",
    "4", "5", "6", "*",
    "1", "2", "3", "-",
    ".", "0", "+", "="};


//------window-------

	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_title(GTK_WINDOW(window), "Calculadora");
	g_signal_connect(window, "delete_event", G_CALLBACK(gtk_main_quit), NULL);
	gtk_window_set_resizable(GTK_WINDOW(window), FALSE);
	gtk_container_set_border_width(GTK_CONTAINER(window), 3);


//------table-------

	table = gtk_grid_new();
	gtk_grid_set_row_spacing(GTK_GRID(table), 2);
	gtk_grid_set_column_spacing(GTK_GRID(table), 2);


//------screen--------

	label = gtk_label_new("0");
	gtk_widget_override_font(label,
			pango_font_description_from_string("Arial 37"));
	gtk_misc_set_alignment(GTK_MISC(label), 1.0f, 1.0f);
	gtk_grid_attach(GTK_GRID(table), label, 0,0,4,1);


//------first row------

	button = gtk_button_new_with_label("AC");
	gtk_grid_attach(GTK_GRID(table), button, 0, 1, 2, 1);
	g_signal_connect(button, "clicked", G_CALLBACK(button_clicked), "AC");

	button = gtk_button_new_with_label("√");
	gtk_grid_attach(GTK_GRID(table), button, 2, 1, 1, 1);
	g_signal_connect(button, "clicked", G_CALLBACK(button_clicked), "=");
	g_signal_connect(button, "clicked", G_CALLBACK(sqroot), "");



	button = gtk_button_new_with_label("x²");
	gtk_grid_attach(GTK_GRID(table), button, 3, 1, 1, 1);
	g_signal_connect(button, "clicked", G_CALLBACK(button_clicked), "=");
	g_signal_connect(button, "clicked", G_CALLBACK(sqexp), "");


//------digit grid----

	int i = 1;
	int j = 0;
	int pos = 0;

	for (i=2; i < 6; i++)
	{
		for (j=0; j < 4; j++)
		{
		button = gtk_button_new_with_label(values[pos]);
		gtk_grid_attach(GTK_GRID(table), button, j, i, 1, 1);
		g_signal_connect(button, "clicked",
				G_CALLBACK(button_clicked), values[pos]);
		pos++;
		}
	}


//---------- infite loop --------

	gtk_container_add(GTK_CONTAINER(window), table);
	gtk_widget_show_all(window);
	gtk_main();
	return 0;
}
