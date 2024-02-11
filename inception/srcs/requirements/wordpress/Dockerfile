FROM debian:bookworm

# Install required packages
RUN apt-get update && \
    DEBIAN_FRONTEND=noninteractive apt-get install -y \
    php8.2 \
    php8.2-fpm \
    php8.2-mysql \
    php8.2-phar \
    php8.2-mbstring \
    php8.2-redis \
    php8.2-ctype \
    gettext \
    wget \
    && rm -rf /var/lib/apt/lists/*

# Download and install wp-cli
RUN wget https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar \
    && chmod +x wp-cli.phar \
    && mv wp-cli.phar /usr/local/bin/wp

# Copy configuration files
COPY conf/php.ini /etc/php/8.2/conf.d/50-setting.ini
COPY conf/wp-config.php /
COPY tools/wp_init.sh /

# Set the working directory
WORKDIR /

# Command to run on container startup
CMD ["./wp_init.sh"]
