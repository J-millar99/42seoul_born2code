FROM debian:bookworm

# Install MariaDB server and client
RUN apt-get update && \
    DEBIAN_FRONTEND=noninteractive apt-get install -y \
    mariadb-server \
    mariadb-client \
    && rm -rf /var/lib/apt/lists/*

# Copy MariaDB configuration file
COPY conf/my.cnf /etc/mysql/my.cnf

# Copy start script
COPY tools/start.sh /db/start.sh

# Create necessary directories and set ownership
RUN mkdir -p /run/mysqld /var/log/mysql && \
    chown -R mysql:mysql /var/lib/mysql /run/mysqld /var/log/mysql

# Switch to the mysql user
USER mysql

# Command to run on container startup
CMD ["/db/start.sh"]
