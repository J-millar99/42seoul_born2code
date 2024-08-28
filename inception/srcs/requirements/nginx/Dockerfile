FROM debian:11
EXPOSE 443

RUN apt-get update && apt-get install -y nginx tini openssl

COPY ./conf/nginx.conf /etc/nginx/
COPY ./tools/api_setup.sh /bin/

RUN chmod +x /bin/api_setup.sh

# ENTRYPOINT ["/usr/bin/tini", "--"]
CMD ["/bin/api_setup.sh"]