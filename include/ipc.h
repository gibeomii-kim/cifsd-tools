// SPDX-License-Identifier: GPL-2.0-or-later
/*
 *   Copyright (C) 2018 Samsung Electronics Co., Ltd.
 *
 *   linux-cifsd-devel@lists.sourceforge.net
 */

#ifndef __SMBD_IPC_H__
#define __SMBD_IPC_H__

/*
 * Older [prior to 4.9] kernels had max NL recv msg size of 16k.
 * It has been bumped to 32K later on.
 */
#define SMBD_IPC_MAX_MESSAGE_SIZE	(16 * 1024)

struct smbd_ipc_msg {
	unsigned int	type;
	unsigned int	sz;
	unsigned char	____payload[0];
};

#define SMBD_IPC_MSG_PAYLOAD(m)				\
	(void *)(((struct smbd_ipc_msg *)(m))->____payload)

#define SMBD_STATUS_IPC_FATAL_ERROR	11

struct smbd_ipc_msg *ipc_msg_alloc(size_t sz);
void ipc_msg_free(struct smbd_ipc_msg *msg);

int ipc_msg_send(struct smbd_ipc_msg *msg);

int ipc_process_event(void);
void ipc_destroy(void);
int ipc_init(void);

#endif /* __SMBD_IPC_H__ */
