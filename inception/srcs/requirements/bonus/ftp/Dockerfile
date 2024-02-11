FROM debian:bookworm

# Install vsftpd
RUN apt-get update && \
    DEBIAN_FRONTEND=noninteractive apt-get install -y \
    vsftpd \
    && rm -rf /var/lib/apt/lists/*

# Copy vsftpd configuration
COPY conf/vsftpd.conf /etc/vsftpd.conf

# Copy startup script
COPY tools/ftp.sh /ftp.sh

# Make startup script executable
RUN chmod +x /ftp.sh

# Command to run on container startup
CMD ["/ftp.sh"]
