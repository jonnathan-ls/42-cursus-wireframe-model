// #include "fdf.h"

// #define ISO_ANGLE 0.523599 // 30 degrees in radians
// #define SCALE 20

// void apply_isometric_projection(t_config *conf) {
//     for (int i = 0; i < conf->height; i++) {
//         for (int j = 0; j < conf->width; j++) {
//             int x = conf->points[i][j].x;
//             int y = conf->points[i][j].y;
//             int z = conf->points[i][j].z;
//             conf->points[i][j].x = (x - y) * cos(ISO_ANGLE);
//             conf->points[i][j].y = (x + y) * sin(ISO_ANGLE) - z;
//         }
//     }
// }

// void draw_horizontal_lines(t_config *conf) {
//     for (int i = 0; i < conf->height; i++) {
//         for (int j = 0; j < conf->width - 1; j++) {
//             t_point start = conf->points[i][j];
//             t_point end = conf->points[i][j + 1];
//             conf->draw_params = (t_draw_params){start, end, 0, 0, 0.0, &conf->img};
//             draw_line(&conf->draw_params);
//         }
//     }
// }

// void draw_vertical_lines(t_config *conf) {
//     for (int i = 0; i < conf->height - 1; i++) {
//         for (int j = 0; j < conf->width; j++) {
//             t_point start = conf->points[i][j];
//             t_point end = conf->points[i + 1][j];
//             conf->draw_params = (t_draw_params){start, end, 0, 0, 0.0, &conf->img};
//             draw_line(&conf->draw_params);
//         }
//     }
// }

// void draw_lines(t_config *conf) {
//     draw_horizontal_lines(conf);
//     draw_vertical_lines(conf);
// }

// void process_points(t_config *conf) {
//     apply_isometric_projection(conf);
//     draw_lines(conf);
// }