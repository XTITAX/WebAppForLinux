import webview

def create_window():
    webview.create_window("Кнопки", "index.html", width=800, height=600)

    # Определяем функцию для закрытия окна через API
    def close_window():
        webview.destroy_window()

    webview.start(func=close_window)

if __name__ == "__main__":
    create_window()
