INCLUDE_DIR = include
MLX_DIR = minilibx-linux
SRC_DIR = src
BUILD_DIR = build

CC = cc
CFLAGS = -Werror -Wall -Wextra -g
CPPFLAGS = -I $(INCLUDE_DIR) -I $(MLX_DIR)
LDFLAGS = -L $(MLX_DIR) -lmlx -lXext -lX11 -lbsd -lm

CUB3D_SRCS =	bin/cub3d/main.c \
							error/err_free.c \
							error/err_loc.c \
							error/err_new_fmt.c \
							error/err_new_vfmt.c \
							error/err_oom.c \
							error/err_wrap_fmt.c \
							error/err_wrap_vfmt.c \
							filesystem/file_close.c \
							filesystem/file_open.c \
							filesystem/file_read.c \
							filesystem/rbuf_close.c \
							filesystem/rbuf_fill.c \
							filesystem/rbuf_open.c \
							filesystem/rbuf_read_exact.c \
							filesystem/rbuf_try_read_byte.c \
							format/fmt_format.c \
							format/fmt_vformat.c \
							hook/key_hook.c \
							hook/loop_hook.c \
							hook/is_key_pressed.c \
							hook/key_release_hook.c \
							hook/destroy_hook.c \
							load/creat_window.c \
							load/creat_image.c \
							load/creat_rays.c \
							load/free_game.c \
							load/free_texture.c \
							load/load_cub.c \
							load/image_load.c \
							load/load_game.c \
							load/init_image.c \
							load/init_texture.c \
							load/init_color_pixel.c \
							load/init_game.c \
							display/write_all.c \
							display/display_map.c \
							display/compose_image.c \
							display/init_step_and_side.c \
							display/init_delta_distance.c \
							display/init_ray.c \
							display/dda.c \
							display/calculating_perpenticular_dist.c \
							display/get_dir.c \
							display/calculating_terminals_for_draw.c \
							display/get_pixel_color.c \
							display/my_put_pixel.c \
							display/compute_rays.c \
							display/compose_wall.c \
							move/move_player.c \
							move/rotate_player.c \
							move/move_player_front_and_rear.c \
							move/move_player_side.c \
							move/is_wall.c \
							parsing/we_have_all_info_each_elem.c \
							parsing/map_valid.c \
							parsing/map_close.c \
							parsing/path_player_in_map.c \
							parsing/fill_map.c \
							parsing/fill_line_map.c \
							parsing/free_map.c \
							parsing/size_max_line.c \
							parsing/check_elem_map_valid.c \
							parsing/look_and_push_char.c \
							parsing/free_map_no_valid.c \
							parsing/is_char_authorize.c \
							parsing/init_type.c \
							parsing/init_line.c \
							parsing/init_lines.c \
							parsing/push_str.c \
							parsing/push_char.c \
							parsing/check_elem.c \
							parsing/look_info.c \
							parsing/look_type.c \
							parsing/info_final_error.c \
							parsing/space_between_type_and_info.c \
							parsing/add_zero_end_line.c \
							parsing/type_identifier_and_info.c \
							parsing/save_info_with_type.c \
							parsing/who_type_and_type_is_ok.c \
							parsing/save_atoi_rgb.c \
							parsing/is_type.c \
							parsing/is_dir.c \
							parsing/is_type_exist.c \
							parsing/while_is_space.c \
							parsing/free_lines.c \
							parsing/free_dir.c \
							parsing/file_valid.c \
							parsing/recovering_info_befor_map.c \
							parsing/file_name_valid.c \
							parsing/pars_size_after_delet_space_end_str.c \
							string/ft_memcpy.c \
							string/ft_strlen.c \
							string/str_free.c \
							string/str_from_cstr.c \
							string/string_free.c \
							string/string_from_cstr.c \
							string/string_from_str.c \
							string/string_new.c \
							string/string_push_char.c \
							string/string_push_str.c

BONUS_SRCS = 	bin/cub3d_bonus/main.c \
							error/err_free.c \
							error/err_loc.c \
							error/err_new_fmt.c \
							error/err_new_vfmt.c \
							error/err_oom.c \
							error/err_wrap_fmt.c \
							error/err_wrap_vfmt.c \
							filesystem/file_close.c \
							filesystem/file_open.c \
							filesystem/file_read.c \
							filesystem/rbuf_close.c \
							filesystem/rbuf_fill.c \
							filesystem/rbuf_open.c \
							filesystem/rbuf_read_exact.c \
							filesystem/rbuf_try_read_byte.c \
							format/fmt_format.c \
							format/fmt_vformat.c \
							hook/key_pressed_mouse_bonus.c \
							hook/key_release_mouse_hook_bonus.c \
							hook/key_hook.c \
							hook/loop_hook.c \
							hook/is_key_pressed.c \
							hook/key_release_hook.c \
							hook/destroy_hook.c \
							load/init_sprite_bonus.c \
							load/init_sprite_summer_bonus.c \
							load/init_sprite_winter_bonus.c \
							load/init_sprite_autumn_bonus.c \
							load/init_sprite_spring_bonus.c \
							load/init_one_sprite_bonus.c \
							load/creat_window.c \
							load/creat_image.c \
							load/creat_rays.c \
							load/free_arrow_bonus.c \
							load/free_game_bonus.c \
							load/free_texture.c \
							load/load_cub_bonus.c \
							load/image_load.c \
							load/load_game_bonus.c \
							load/init_image.c \
							load/init_texture_bonus.c \
							load/init_color_pixel.c \
							load/init_game.c \
							display/write_all.c \
							display/map_bonus.c \
							display/display_map_bonus.c \
							display/compose_image_bonus.c \
							display/init_step_and_side.c \
							display/init_delta_distance.c \
							display/init_ray.c \
							display/dda_bonus.c \
							display/calculating_perpenticular_dist.c \
							display/get_dir.c \
							display/calculating_terminals_for_draw.c \
							display/get_pixel_color.c \
							display/my_put_pixel.c \
							display/compute_rays.c \
							display/compose_wall_bonus.c \
							move/mouse_move_bonus.c \
							move/move_player.c \
							move/rotate_player.c \
							move/move_player_front_and_rear.c \
							move/move_player_side.c \
							move/is_wall.c \
							parsing/we_have_all_info_each_elem_bonus.c \
							parsing/map_valid.c \
							parsing/map_close.c \
							parsing/path_player_in_map.c \
							parsing/fill_map.c \
							parsing/fill_line_map.c \
							parsing/free_map.c \
							parsing/size_max_line.c \
							parsing/check_elem_map_valid.c \
							parsing/look_and_push_char.c \
							parsing/free_map_no_valid.c \
							parsing/is_char_authorize_bonus.c \
							parsing/init_type.c \
							parsing/init_line.c \
							parsing/init_lines.c \
							parsing/push_str.c \
							parsing/push_char.c \
							parsing/check_elem.c \
							parsing/look_info.c \
							parsing/look_type.c \
							parsing/info_final_error.c \
							parsing/space_between_type_and_info.c \
							parsing/add_zero_end_line.c \
							parsing/type_identifier_and_info_bonus.c \
							parsing/save_info_with_type.c \
							parsing/who_type_and_type_is_ok_bonus.c \
							parsing/save_atoi_rgb.c \
							parsing/is_type_bonus.c \
							parsing/is_dir.c \
							parsing/is_type_exist_bonus.c \
							parsing/while_is_space.c \
							parsing/free_lines.c \
							parsing/free_dir.c \
							parsing/file_valid.c \
							parsing/recovering_info_befor_map.c \
							parsing/file_name_valid.c \
							parsing/pars_size_after_delet_space_end_str.c \
							string/ft_memcpy.c \
							string/ft_strlen.c \
							string/str_free.c \
							string/str_from_cstr.c \
							string/string_free.c \
							string/string_from_cstr.c \
							string/string_from_str.c \
							string/string_new.c \
							string/string_push_char.c \
							string/string_push_str.c

SRCS = $(CUB3D_SRCS)
SRCS_BONUS = $(BONUS_SRCS)
CUB3D_OBJS = $(addprefix $(BUILD_DIR)/,$(SRCS:.c=.o))
BONUS_OBJS = $(addprefix $(BUILD_DIR)/,$(SRCS_BONUS:.c=.o))
OBJS = $(CUB3D_OBJS) $(BONUS_OBJS)
DEPS = $(OBJS:.o=.d)
BINS = cub3D

all: $(BINS)

.PHONY: all

$(BINS): $(CUB3D_OBJS)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

.SECONDEXPANSION:
.SECOND:

$(BUILD_DIR)/.:
	mkdir -p $@

$(BUILD_DIR)%/.:
	mkdir -p $@

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c | $$(@D)/.
	$(CC) $(CFLAGS) $(CPPFLAGS) -MMD -c $< -o $@

.PHONY: bonus

bonus: CFLAGS += -DBONUS
bonus: $(BONUS_OBJS)
	$(CC) $(CFLAGS) -o $(BINS) $^ $(LDFLAGS)

.PHONY: clean
clean:
	$(RM) $(OBJS) $(DEPS)

.PHONY: fclean
fclean: clean
	$(RM) $(BINS)

.PHONY: re
re:
	$(MAKE) fclean
	$(MAKE) all

-include $(DEPS)
