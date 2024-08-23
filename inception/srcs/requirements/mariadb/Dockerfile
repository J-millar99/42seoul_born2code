FROM debian:11
EXPOSE 3306

RUN	apt-get update && apt-get install -y mariadb-server tini

COPY	conf/50-server.cnf /etc/mysql/mariadb.conf.d/

COPY	tools/setup.sh /bin/
RUN		chmod +x /bin/setup.sh

ENTRYPOINT	["/usr/bin/tini", "--"]

CMD ["setup.sh", "mysqld_safe"]