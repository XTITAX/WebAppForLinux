#include <gtk/gtk.h>

// Функция-обработчик события нажатия на кнопку
void calculate_sum(GtkWidget *widget, gpointer data) {
    GtkWidget *entry1 = (GtkWidget *)data;
    GtkWidget *entry2 = (GtkWidget *)g_object_get_data(G_OBJECT(widget), "entry2");
    GtkWidget *result_label = (GtkWidget *)g_object_get_data(G_OBJECT(widget), "result_label");

    // Получаем введенные пользователем значения
    const gchar *num1_str = gtk_entry_get_text(GTK_ENTRY(entry1));
    const gchar *num2_str = gtk_entry_get_text(GTK_ENTRY(entry2));

    // Преобразуем текст в числа
    int num1 = atoi(num1_str);
    int num2 = atoi(num2_str);

    // Вычисляем сумму
    int sum = num1 + num2;

    // Преобразуем результат обратно в строку для вывода
    gchar *result_str = g_strdup_printf("Сумма: %d", sum);

    // Обновляем текст метки с результатом
    gtk_label_set_text(GTK_LABEL(result_label), result_str);

    // Освобождаем выделенную память
    g_free(result_str);
}

int main(int argc, char *argv[]) {
    GtkWidget *window;
    GtkWidget *grid;
    GtkWidget *entry1;
    GtkWidget *entry2;
    GtkWidget *calculate_button;
    GtkWidget *result_label;

    gtk_init(&argc, &argv);

    // Создаем главное окно
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Калькулятор суммы");
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    // Устанавливаем размеры окна
    gtk_window_set_default_size(GTK_WINDOW(window), 400, 300);

    // Устанавливаем окно по центру экрана
    gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);

    // Создаем сетку для размещения элементов
    grid = gtk_grid_new();
    gtk_container_add(GTK_CONTAINER(window), grid);

    // Поле ввода для первого числа
    entry1 = gtk_entry_new();
    gtk_grid_attach(GTK_GRID(grid), entry1, 0, 0, 1, 1);
    gtk_widget_set_halign(entry1, GTK_ALIGN_CENTER); // Выравнивание по горизонтали
    gtk_widget_set_valign(entry1, GTK_ALIGN_CENTER); // Выравнивание по вертикали

    // Поле ввода для второго числа
    entry2 = gtk_entry_new();
    gtk_grid_attach(GTK_GRID(grid), entry2, 0, 1, 1, 1);
    gtk_widget_set_halign(entry2, GTK_ALIGN_CENTER); // Выравнивание по горизонтали
    gtk_widget_set_valign(entry2, GTK_ALIGN_CENTER); // Выравнивание по вертикали

    // Кнопка для вычисления суммы
    calculate_button = gtk_button_new_with_label("Вычислить сумму");
    gtk_grid_attach(GTK_GRID(grid), calculate_button, 0, 2, 1, 1);
    gtk_widget_set_halign(calculate_button, GTK_ALIGN_CENTER); // Выравнивание по горизонтали
    gtk_widget_set_valign(calculate_button, GTK_ALIGN_CENTER); // Выравнивание по вертикали

    // Метка для вывода результата
    result_label = gtk_label_new("Результат:");
    gtk_grid_attach(GTK_GRID(grid), result_label, 0, 3, 1, 1);
    gtk_widget_set_halign(result_label, GTK_ALIGN_CENTER); // Выравнивание по горизонтали
    gtk_widget_set_valign(result_label, GTK_ALIGN_CENTER); // Выравнивание по вертикали

    // Соединяем событие нажатия на кнопку с функцией-обработчиком
    g_signal_connect(calculate_button, "clicked", G_CALLBACK(calculate_sum), entry1);
    g_object_set_data(G_OBJECT(calculate_button), "entry2", entry2);
    g_object_set_data(G_OBJECT(calculate_button), "result_label", result_label);

    // Отображаем все виджеты
    gtk_widget_show_all(window);

    // Запускаем главный цикл обработки событий
    gtk_main();

    return 0;
}
