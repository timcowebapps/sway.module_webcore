"use strict";

export class AbstractModel {
	public _wasm_model: any = null;

	constructor(context: any) {
		this._wasm_model = new context.module.AbstractModel();
	}

	public getProperties(): any {
		return this._wasm_model.getProperties();
	}

	public setProperty(key, value): void {
		this._wasm_model.setProperty(key, value);
	}
};
