NAME = inception
SRCS = ./srcs/
COMPOSE = ./srcs/docker-compose.yml

all:	conf up

conf:
	mkdir -p /home/jaehyji/data/mariadb /home/jaehyji/data/wordpress
	sudo sed -i '/^127.0.0.1/ {/jaehyji.42.fr/! s/localhost/localhost jaehyji.42.fr/}' /etc/hosts

up:	
	docker compose -p $(NAME) -f $(COMPOSE) up --build -d
	@sleep 1

down:
	docker compose -p $(NAME) down --volumes

start:
	docker compose -p $(NAME) start

stop:
	docker compose -p $(NAME) stop

clean-images:
	docker rmi -f $$(docker images -q) || true	

clean: down clean-images

fclean: clean
	@sudo rm -rf /home/jaehyji/data
	@sudo docker system prune

re: fclean conf up