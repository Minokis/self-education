import React from 'react'
export default class UserGuestIdRow extends React.Component {
	render() {
		const user = this.props.user;
		return (
		<div class="row justify-content-start">
					<div class="col-3">Твой ключ наблюдателя: {user.guestId}</div>
				</div>
		);
	}
}
