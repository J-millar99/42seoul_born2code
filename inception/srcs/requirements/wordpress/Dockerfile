FROM debian:11
EXPOSE	9000

RUN		apt-get update && apt-get install -y ca-certificates \
		php7.4-fpm php7.4-mysql \
		mariadb-client wget tar tini

RUN	wget https://wordpress.org/wordpress-6.3.1.tar.gz -P /var/www
RUN	cd /var/www && tar -xzf wordpress-6.3.1.tar.gz && rm wordpress-6.3.1.tar.gz

COPY	./conf/wp-config.php /var/www/wordpress/

RUN	chown -R root:root /var/www/wordpress

COPY	./conf/www.conf /etc/php/7.4/fpm/pool.d/
RUN	mkdir -p /run/php

RUN	wget https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar
RUN	chmod +x wp-cli.phar
RUN	mv wp-cli.phar /usr/local/bin/wp

COPY	./tools/setup.sh /bin/
RUN	chmod +x /bin/setup.sh

# ENTRYPOINT ["/usr/bin/tini", "--"]

CMD ["/bin/setup.sh"]