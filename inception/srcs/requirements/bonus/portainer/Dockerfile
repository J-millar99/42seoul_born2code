FROM debian:bookworm

RUN apt-get update && \
    DEBIAN_FRONTEND=noninteractive apt-get install -y \
    curl \
    && rm -rf /var/lib/apt/lists/*

RUN curl -L https://github.com/portainer/portainer/releases/download/2.18.4/portainer-2.18.4-linux-amd64.tar.gz -o portainer.tar.gz \
    && tar -xvf portainer.tar.gz \
    && mv portainer /usr/local/bin/ \
    && rm portainer.tar.gz

CMD ["/usr/local/bin/portainer/portainer"]
