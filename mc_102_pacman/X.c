void close_button_handler(void) //Permite a utilização do botão "Fechar" para fechar o aplicativo
{
    close_button_pressed = TRUE;
}
END_OF_FUNCTION(close_button_handler)

int main(void)
{
    LOCK_FUNCTION(close_button_handler);
    set_close_button_callback(close_button_handler);


while (!close_button_pressed && !key[KEY_ESC])
{

}
