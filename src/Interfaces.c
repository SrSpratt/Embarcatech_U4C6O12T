#include <Interfaces_U4C6.h>

void I2CInit(ssd1306_t* ssd){
    i2c_init(I2C_PORT, 400 * 1000);
    gpio_set_function(I2C_SDA, GPIO_FUNC_I2C);
    gpio_set_function(I2C_SCL, GPIO_FUNC_I2C);
    gpio_pull_up(I2C_SDA);
    gpio_pull_up(I2C_SCL);
    
    ssd1306_init(ssd, WIDTH, HEIGHT, false, endereco, I2C_PORT);
    ssd1306_config(ssd); // Configura o display
    ssd1306_send_data(ssd); // Envia os dados para o display

    // Limpa o display. O display inicia com todos os pixels apagados.
    ssd1306_fill(ssd, false);
    ssd1306_send_data(ssd);
}

void I2CDraw(ssd1306_t* ssd, bool cor, char* string){
    // Atualiza o conteúdo do display com animações
    ssd1306_fill(ssd, !cor); // Limpa o display
    ssd1306_rect(ssd, 3, 3, 122, 58, cor, !cor); // Desenha um retângulo
    //ssd1306_draw_string(&ssd, "CEPEDI   TIC37", 8, 10); // Desenha uma string
    ssd1306_draw_string(ssd, string, 10, 30); // Desenha uma string
    //ssd1306_draw_string(ssd, "mnopqrstuvxwz", 10, 48); // Desenha uma string      
    ssd1306_send_data(ssd); // Atualiza o display

    //sleep_ms(1000);
}