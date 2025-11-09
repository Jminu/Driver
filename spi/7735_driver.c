#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/module.h>
#include <linux/spi/spi.h>
#include <linux/of.h>
#include <linux/delay.h>
#include <linux/gpio/consumer.h>

static struct st7735_priv {
    struct spi_device *spi;
    struct gpio_desc *reset; // BCM 22
    struct gpio_desc *dc; // BCM 17
    struct gpio_desc *bl; // BCM 27
};

// spi드라이버를 디바이스에 바인딩
static int st7735_custom_probe(struct spi_device *spi) {
    struct device *dev = &spi->dev;
    struct st7735_priv *priv;
    int ret;

    priv = devm_kzalloc(dev, sizeof(struct st7735_priv), GFP_KERNEL);
    priv->spi = spi;

    priv->reset = devm_gpiod_get(dev, "reset", GPIOD_OUT_HIGH);
    priv->dc = devm_gipod_get(dev, "dc", GPIOD_OUT_HIGH);
    priv->bl = devm_gpiod_get(dev, "bl", GPIOD_OUT_HIGH);

    spi_set_drvdata(spi, priv);
    
    printk(KERN_INFO "Probe func success\n");

    return 0;
}

// spi드라이버를 디바이스에 언바인딩
static void st7735_custom_remove(struct spi_device *spi) {
    printk(KERN_INFO "Remove func success\n");

    return 0;
}

static const struct of_device_id st7735_custom_id[] = {
    {.compatible = "my-custom,st7735"}, // .dts하고 일치
    {},
};
MODULE_DEVICE_TABLE(of, st7735_custom_id);

static struct spi_driver st7735_custom_driver = {
    .driver = {
        .name = "st7735_custom",
        .of_match_table = st7735_custom_id,
    },
    .probe = st7735_custom_probe,
    .remove = st7735_custom_remove,
};

module_spi_driver(st7735_custom_driver);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("JIN MINU");