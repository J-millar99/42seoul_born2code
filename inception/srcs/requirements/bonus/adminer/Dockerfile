FROM debian:bookworm

RUN apt-get update && \
    apt-get install -y wget php8.2 php8.2-cli php8.2-mysql php8.2-common php8.2-mbstring && \
    rm -rf /var/lib/apt/lists/*

WORKDIR /var/www/html

RUN wget https://www.adminer.org/latest.php -O adminer.php

COPY conf/php.ini /etc/php/8.2/cli/php.ini

CMD ["php8.2", "-S", "0.0.0.0:8080", "adminer.php"]
