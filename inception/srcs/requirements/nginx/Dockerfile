FROM debian:11
EXPOSE 443

RUN	apt update && apt install -y nginx openssl
RUN mkdir -p /etc/nginx/certs/ && \
	openssl req -newkey rsa:4096 -x509 -sha256 -nodes \
    -out /etc/nginx/certs/jaehyji.42.fr.crt \
    -keyout /etc/nginx/certs/jaehyji.42.fr.key \
    -subj "/C=KR/ST=Seoul/L=Gaepo/O=42/OU=Ecole/CN=jaehyji.42.fr"

COPY ./conf/nginx.conf /etc/nginx/

RUN chmod 755 /var/www/html
RUN chown -R www-data:www-data /var/www/html

ENTRYPOINT ["nginx", "-g", "daemon off;"]